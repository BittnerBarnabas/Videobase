#include "rentalediting.h"

namespace View
{
	rentalEditing::rentalEditing(QWidget * parent) : QWidget(parent), Model(std::make_unique<Implementation::rentalEditImpl>()) {
		ui.setupUi(this);
		ui.rentalsTableView->setModel(Model->tableModel.get());
		ui.rentalsTableView->setColumnHidden(Model->tableModel->fieldIndex("rent_id"), true);
		ui.rentalsTableView->setItemDelegate(new rentalEditingDelegate(ui.rentalsTableView,Model->tableModel.get()->fieldIndex("ret_date")));
	}
	
	rentalEditing::~rentalEditing() {
		
	}
}
