#ifndef BOOKEDITDELEGATE_H
#define BOOKEDITDELEGATE_H

#include <QItemDelegate>

class bookEditDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	bookEditDelegate(QObject *parent);
	~bookEditDelegate();

private:
	
};

#endif // BOOKEDITDELEGATE_H
