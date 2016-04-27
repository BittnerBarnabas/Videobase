#include "mainwindow.h"
#include <QMainWindow>
#include <QDataWidgetMapper>
#include <QLayout>
#include "Implementation/databasehandler.h"
#include "ui_mainwindow.h"

namespace View
{
	MainWindow::MainWindow(QWidget* parent)
	    : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()) {
	  SQLStorage::createSqlConnection();
	  movieEditWidget = nullptr;
	
	  ui->setupUi(this);
	  connect(ui->actionView_Movies, SIGNAL(triggered()), this, SLOT(editMovies()));
	}
	
	MainWindow::~MainWindow() {}
	
	void MainWindow::editMovies() {
	  movieEditWidget = std::make_unique<MovieEdit>();
	  ui->controlLayout->addWidget(movieEditWidget.get());
	}
}