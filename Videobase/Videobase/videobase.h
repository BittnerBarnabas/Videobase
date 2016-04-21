#ifndef VIDEOBASE_H
#define VIDEOBASE_H

#include <QtWidgets/QMainWindow>
#include "ui_videobase.h"

class Videobase : public QMainWindow
{
	Q_OBJECT

public:
	Videobase(QWidget *parent = 0);
	~Videobase();

private:
	Ui::VideobaseClass ui;
};

#endif // VIDEOBASE_H
