#pragma once
#include <QWidget>
#include "ui_videobase.h"

class Videobase : public QWidget {
	Q_OBJECT

public:
	Videobase(QWidget * parent = Q_NULLPTR);
	~Videobase();

private:
	Ui::Videobase ui;
};
