#include "bookeditdelegate.h"

bookEditDelegate::bookEditDelegate(int lockedColumnN,QObject *parent)
	: QSqlRelationalDelegate(parent),lockedColumnN(lockedColumnN)
{

}

bookEditDelegate::~bookEditDelegate()
{

}

QWidget * bookEditDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	if (index.column() == lockedColumnN)
	{
		auto* lockingSelector = new QComboBox(parent);
		lockingSelector->addItem("No", 0);
		lockingSelector->addItem("Yes", 1);
		return lockingSelector;
	}
	return QSqlRelationalDelegate::createEditor(parent, option, index);
}

void bookEditDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const
{
	if (index.column() == lockedColumnN)
		dynamic_cast<QComboBox*>(editor)->setCurrentIndex(index.model()->data(index).toInt());
	else
		QSqlRelationalDelegate::setEditorData(editor, index);
}

void bookEditDelegate::setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const
{
	if (index.column() == lockedColumnN)
		model->setData(index, dynamic_cast<QComboBox*>(editor)->currentIndex());
	else
		QSqlRelationalDelegate::setModelData(editor, model, index);
}

void bookEditDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	if (index.column() == lockedColumnN)
	{
		painter->drawText(option.rect.x(), option.rect.y(), "Yes");
	}
	QSqlRelationalDelegate::paint(painter, option, index);
}
