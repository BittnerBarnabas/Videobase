#pragma once
#include <QObject>
#include <QPainter>
#include <QSqlRelationalDelegate>

namespace View {
class rentalEditingDelegate : public QSqlRelationalDelegate {
  Q_OBJECT

 public:
  rentalEditingDelegate(
      QObject *parent = Q_NULLPTR,
      int dateColNum =
          4);  //!< Receives the column number where the return dates are stored
  ~rentalEditingDelegate();
  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override; //!< Instead the default date, prints message
  QWidget *createEditor(QWidget *aParent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const override; //!< prevents the fields from being edited

 private:
  int currentDateCol;
};
}
