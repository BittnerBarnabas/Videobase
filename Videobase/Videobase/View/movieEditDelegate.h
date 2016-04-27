#ifndef BOOKEDITDELEGATE_H
#define BOOKEDITDELEGATE_H

#include <QSqlRelationalDelegate>
#include <QComboBox>
#include <QPainter>

namespace View
{
	class movieEditDelegate : public QSqlRelationalDelegate
	{
		Q_OBJECT
	public:
		movieEditDelegate(int lockedColumnN,QObject *parent = Q_NULLPTR);
		~movieEditDelegate();
		QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
		void setEditorData(QWidget *editor, const QModelIndex &index) const override;
		void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
		void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	
	
	private:
		//mutable QComboBox* lockingSelector;
		int lockedColumnN;
	};
}

#endif // BOOKEDITDELEGATE_H
