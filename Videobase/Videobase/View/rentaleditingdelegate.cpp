#include "rentaleditingdelegate.h"

namespace View {
rentalEditingDelegate::rentalEditingDelegate(QObject* parent, int dateColNum)
    : QSqlRelationalDelegate(parent), currentDateCol(dateColNum) {}

rentalEditingDelegate::~rentalEditingDelegate() {}

void rentalEditingDelegate::paint(QPainter* painter,
                                  const QStyleOptionViewItem& option,
                                  const QModelIndex& index) const {
  if (currentDateCol == index.column()) {
    if (index.model()->data(index) == "2001-01-01") {
      if (option.state & QStyle::State_Selected) {
        if (option.state & QStyle::State_Active) {
          painter->fillRect(option.rect, option.palette.highlight().color());

        } else {
          QPalette p = option.palette;
          painter->fillRect(option.rect,
                            p.color(QPalette::Inactive, QPalette::Background));
        }
      }
      painter->drawText(option.rect.x() + 3, option.rect.y() + 25,
                        "Not returned yet");
      return;
    }
  }
  QSqlRelationalDelegate::paint(painter, option, index);
}
QWidget* rentalEditingDelegate::createEditor(QWidget* aParent,
                                             const QStyleOptionViewItem& option,
                                             const QModelIndex& index) const {
  return nullptr;
}
}
