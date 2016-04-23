#include "mainwindow.h"
#include <QDataWidgetMapper>
#include "Implementation/databasehandler.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()) {
  SQLStorage::createSqlConnection();
  bookEditWidget = nullptr;

  ui->setupUi(this);
  connect(ui->actionView_Movies, SIGNAL(triggered()), this, SLOT(editMovies()));
}

MainWindow::~MainWindow() {}

void MainWindow::editMovies() {
  bookEditWidget = std::make_unique<bookEdit>();
  ui->controlLayout->addWidget(bookEditWidget.get());
}