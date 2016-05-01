#include "rentalediting.h"

namespace View {
rentalEditing::rentalEditing(QWidget* parent)
    : QWidget(parent),
      Model(std::make_unique<Implementation::rentalEditImpl>()) {
  ui.setupUi(this);
  setUpTableView();
  connect(ui.newRentalButton, SIGNAL(clicked()), Model.get(),
          SLOT(insertRowToEnd()));
  connect(ui.applyButton, SIGNAL(clicked()), this, SLOT(submitAll()));
  connect(ui.revertButton, SIGNAL(clicked()), Model->tableModel.get(),
          SLOT(revertAll()));
  connect(ui.movieTitleCombo, SIGNAL(currentIndexChanged(int)), this,
          SLOT(sendTitleFromCombobox(int)));
  connect(this, SIGNAL(titleFromCombobox(int, int)), Model.get(),
          SLOT(updateTitle(int, int)));
}
rentalEditing::~rentalEditing() {}
void rentalEditing::sendTitleFromCombobox(int ind) {
  int mov_id = ui.movieTitleCombo->itemData(ind).toInt();
  emit titleFromCombobox(ui.rentalsTableView->currentIndex().row(), mov_id);
}
void rentalEditing::setUpTableView() {
  auto TableViewModel = Model->tableModel.get();
  //setting up the model, and delegates
  ui.rentalsTableView->setModel(TableViewModel);
  ui.rentalsTableView->setColumnHidden(Model->tableModel->fieldIndex("rent_id"),
                                       true);
  ui.rentalsTableView->setItemDelegate(new rentalEditingDelegate(
      ui.rentalsTableView, TableViewModel->fieldIndex("ret_date")));
  ui.rentalsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
  ui.rentalsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

  setUpMovieTitleEditCombo();
  //setting up other combos with model
  ui.memberNameCombo->setModel(TableViewModel->relationModel(1));
  ui.memberNameCombo->setModelColumn(
      TableViewModel->relationModel(1)->fieldIndex("name"));
  //adding connection between combos and model
  auto* WidgetMapper = new QDataWidgetMapper(this);
  WidgetMapper->setModel(TableViewModel);
  WidgetMapper->setItemDelegate(new rentalEditingDelegate(
      ui.rentalsTableView, TableViewModel->fieldIndex("ret_date")));
  WidgetMapper->addMapping(ui.memberNameCombo, 1);

  connect(ui.rentalsTableView->selectionModel(),
          SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), WidgetMapper,
          SLOT(setCurrentModelIndex(QModelIndex)));
  ui.rentalsTableView->setCurrentIndex(TableViewModel->index(0, 0));
}
void rentalEditing::setUpMovieTitleEditCombo() {
  QSqlQuery rentableQuery(
      "SELECT title,mov_id FROM movies WHERE locked IS false AND mov_id NOT IN "
      "(SELECT mov_id FROM rentals WHERE ret_date  = '2001-01-01') order by "
      "title");
  rentableQuery.setForwardOnly(true);
  int i = 1;
  while (rentableQuery.next()) {
    // storing the title and the index
    ui.movieTitleCombo->addItem(rentableQuery.value(0).toString(),
                                rentableQuery.value(1).toInt());
  }
}
void rentalEditing::submitAll() {
  if (!Model->tableModel->submitAll()) {
    QMessageBox msgBox;
    msgBox.setText(Model->tableModel->lastError().text());
    msgBox.exec();
  }
}
}
