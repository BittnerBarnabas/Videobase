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
	  connect(ui->actionView_Rentals, SIGNAL(triggered()), this, SLOT(editRentals()));
	}
	
	MainWindow::~MainWindow() {}

	void MainWindow::editRentals()
	{
		movieEditWidget.reset(nullptr);
		rentalEditingWidget = std::make_unique<rentalEditing>();
		ui->controlLayout->addWidget(rentalEditingWidget.get());
	}
	
	void MainWindow::editMovies() {
		rentalEditingWidget.reset(nullptr);
	  movieEditWidget = std::make_unique<MovieEdit>();
	  ui->controlLayout->addWidget(movieEditWidget.get());
	}
}