#include "rentalediting.h"

namespace View {
rentalEditing::rentalEditing(QWidget* parent)
    : QWidget(parent),
      Model(std::make_unique<Implementation::rentalEditImpl>()) {
  ui.setupUi(this);
  setUpTableView();
  connect(ui.newRentalButton, SIGNAL(clicked()), Model.get(),
          SLOT(insertRowToEnd()));
  connect(ui.applyButton, SIGNAL(clicked()), Model->tableModel.get(), SLOT(submitAll()));
  connect(ui.revertButton, SIGNAL(clicked()), Model->tableModel.get(), SLOT(revertAll()));
}

rentalEditing::~rentalEditing() {}
void rentalEditing::setUpTableView() {
  auto TableViewModel = Model->tableModel.get();
  ui.rentalsTableView->setModel(TableViewModel);
  ui.rentalsTableView->setColumnHidden(Model->tableModel->fieldIndex("rent_id"),
                                       true);
  ui.rentalsTableView->setItemDelegate(new rentalEditingDelegate(
      ui.rentalsTableView, TableViewModel->fieldIndex("ret_date")));
  ui.rentalsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
  ui.rentalsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

  ui.movieTitleCombo->setModel(TableViewModel->relationModel(2));
  ui.movieTitleCombo->setModelColumn(
      TableViewModel->relationModel(2)->fieldIndex("title"));

  ui.memberNameCombo->setModel(TableViewModel->relationModel(1));
  ui.memberNameCombo->setModelColumn(
      TableViewModel->relationModel(1)->fieldIndex("name"));

  auto* WidgetMapper = new QDataWidgetMapper(this);
  WidgetMapper->setModel(TableViewModel);
  WidgetMapper->setItemDelegate(new rentalEditingDelegate(
      ui.rentalsTableView, TableViewModel->fieldIndex("ret_date")));
  WidgetMapper->addMapping(ui.movieTitleCombo, 2);
  WidgetMapper->addMapping(ui.memberNameCombo, 1);

  connect(ui.rentalsTableView->selectionModel(),
          SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), WidgetMapper,
          SLOT(setCurrentModelIndex(QModelIndex)));
  ui.rentalsTableView->setCurrentIndex(TableViewModel->index(0, 0));
}
}
