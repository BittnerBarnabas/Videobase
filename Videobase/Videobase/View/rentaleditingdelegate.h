#pragma once
#include <QObject>
#include <QSqlRelationalDelegate>
#include <QPainter>

namespace View
{
	class rentalEditingDelegate : public QSqlRelationalDelegate {
		Q_OBJECT
	
	public:
		rentalEditingDelegate(QObject * parent = Q_NULLPTR, int dateColNum = 4);
		~rentalEditingDelegate();
		void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
		QWidget* createEditor(QWidget *aParent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	private:
		int currentDateCol;
	};
}
