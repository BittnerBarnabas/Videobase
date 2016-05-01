#include "movieEditDelegate.h"


namespace View
{	
	movieEditDelegate::movieEditDelegate(int lockedColumnN,QObject *parent)
		: QSqlRelationalDelegate(parent),lockedColumnN(lockedColumnN)
	{
	
	}
	
	movieEditDelegate::~movieEditDelegate()
	{
	
	}
	
	QWidget * movieEditDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
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
	
	void movieEditDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const
	{
		if (index.column() == lockedColumnN)
			dynamic_cast<QComboBox*>(editor)->setCurrentIndex(index.model()->data(index).toInt());
		else
			QSqlRelationalDelegate::setEditorData(editor, index);
	}
	
	void movieEditDelegate::setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const
	{
		if (index.column() == lockedColumnN)
			model->setData(index, dynamic_cast<QComboBox*>(editor)->currentIndex());
		else
			QSqlRelationalDelegate::setModelData(editor, model, index);
	}
	
	void movieEditDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
	{
		if (index.column() != lockedColumnN)
		{
			QSqlRelationalDelegate::paint(painter, option, index);
			return;
		}

		if (option.state & QStyle::State_Selected)
		{
			if (option.state & QStyle::State_Active)
			{
				painter->fillRect(option.rect, option.palette.highlight().color());
				painter->setPen(Qt::white);
			}
			else
			{
				painter->setPen(Qt::black);
				QPalette p = option.palette;
				painter->fillRect(option.rect,
								  p.color(QPalette::Inactive, QPalette::Background));
			}
		}

		if (index.model()->data(index).toInt() == 1)
			painter->drawText(option.rect.x(), option.rect.y() + 25, "Yes");
		else
			painter->drawText(option.rect.x(), option.rect.y() + 25, "No");
	
		painter->setPen(Qt::black);

	}
}
