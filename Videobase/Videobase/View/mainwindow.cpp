#include "mainwindow.h"
#include <QDataWidgetMapper>
#include "Implementation/databasehandler.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  ui = std::make_unique<Ui::MainWindow>();
  ui->setupUi(this);
  populateDBTable();
}

MainWindow::~MainWindow() {}

void MainWindow::populateDBTable() {
  // TODO FIX THIS:
  SQLStorage::createSqlConnection();
  // END TODO

  tableModel = std::make_unique<QSqlRelationalTableModel>(ui->TableDB);
  tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
  tableModel->setTable("rentals");

  int memberIdx = tableModel->fieldIndex("mem_id");
  int movieIdx = tableModel->fieldIndex("mov_id");

  tableModel->setRelation(memberIdx, QSqlRelation("members", "mem_id", "name"));
  tableModel->setRelation(movieIdx, QSqlRelation("movies", "mov_id", "title"));

  tableModel->setHeaderData(memberIdx, Qt::Horizontal, "Rented by");
  tableModel->setHeaderData(movieIdx, Qt::Horizontal, "Movie Title");
  tableModel->setHeaderData(tableModel->fieldIndex("rent_date"), Qt::Horizontal,
                            "Rent Date");
  tableModel->setHeaderData(tableModel->fieldIndex("ret_date"), Qt::Horizontal,
                            "Return Date");

  tableModel->select();

  ui->TableDB->setModel(tableModel.get());
  ui->TableDB->setItemDelegate(new QSqlRelationalDelegate(ui->TableDB));
  ui->TableDB->setColumnHidden(tableModel->fieldIndex("rent_id"), true);
  //ui->TableDB->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->TableDB->setSelectionBehavior(QAbstractItemView::SelectRows);

  auto* DBMapper = new QDataWidgetMapper(this);

  DBMapper->setModel(tableModel.get());
  DBMapper->addMapping(ui->editMovieTitle, memberIdx);



  connect(ui->TableDB->selectionModel(),
          SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), DBMapper,
          SLOT(setCurrentModelIndex(QModelIndex)));
  ui->TableDB->setCurrentIndex(tableModel->index(0, 0));
}
