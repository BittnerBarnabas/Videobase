#include "rentaleditingdelegate.h"

namespace View
{
	rentalEditingDelegate::rentalEditingDelegate(QObject * parent, int dateColNum) : QSqlRelationalDelegate(parent), currentDateCol(dateColNum){
		
	}
	
	rentalEditingDelegate::~rentalEditingDelegate() {
		
	}
	
	void rentalEditingDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
	{
		if (currentDateCol == index.column())
		{
			if (index.model()->data(index) == "2001-01-01")
			{
				if (option.state & QStyle::State_Selected)
				{
					painter->fillRect(option.rect, option.palette.highlight().color());
				}
				painter->drawText(option.rect.x() + 3, option.rect.y() + 25, "Not returned yet");
				return;
			}
		}
		QSqlRelationalDelegate::paint(painter, option, index);
	}
	QWidget* rentalEditingDelegate::createEditor(QWidget * aParent, const QStyleOptionViewItem & option, const QModelIndex & index) const
	{
		return nullptr;
	}
}
