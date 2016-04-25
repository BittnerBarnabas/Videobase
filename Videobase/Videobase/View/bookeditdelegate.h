#ifndef BOOKEDITDELEGATE_H
#define BOOKEDITDELEGATE_H

#include <QSqlRelationalDelegate>
#include <QComboBox>
#include <QPainter>

class bookEditDelegate : public QSqlRelationalDelegate
{
	Q_OBJECT
public:
	bookEditDelegate(int lockedColumnN,QObject *parent = Q_NULLPTR);
	~bookEditDelegate();
	QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	void setEditorData(QWidget *editor, const QModelIndex &index) const override;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;


private:
	//mutable QComboBox* lockingSelector;
	int lockedColumnN;
};

#endif // BOOKEDITDELEGATE_H
