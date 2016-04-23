#pragma once
#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include "View/bookedit.h"
#include <memory>
namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget * parent = Q_NULLPTR);
	~MainWindow();
public slots:
	void editMovies();
private:
	std::unique_ptr<Ui::MainWindow> ui;
	std::unique_ptr<bookEdit> bookEditWidget;
};
