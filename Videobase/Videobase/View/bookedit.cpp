#include "bookedit.h"
#include "bookeditdelegate.h"
bookEdit::bookEdit(QWidget * parent) : QWidget(parent), Impl(std::make_unique<Implementation::bookEditImpl>())
{
	ui.setupUi(this);

	connect(ui.buttonSubmit, SIGNAL(clicked()), Impl.get(), SLOT(submitAll()));
	connect(ui.buttonRevert, SIGNAL(clicked()), Impl.get(), SLOT(revertAll()));
	connect(ui.buttonNewRow, SIGNAL(clicked()), Impl.get(), SLOT(insertRowToEnd()));
	connect(ui.buttonDelRow, SIGNAL(clicked()), this, SLOT(deleteCurrentRow()));
	connect(ui.checkBoxRentableToggle, SIGNAL(stateChanged(int)), Impl.get(), SLOT(toggleRentable(int)));
	connect(ui.checkBoxRentableToggle, SIGNAL(stateChanged(int)), this, SLOT(toggleDeleteButton(int)));
	connect(this, SIGNAL(sendRowIndexToBeDeleted(int)), Impl.get(), SLOT(deleteCurrentRow(int)));

	ui.TableDB->setModel(Impl->tableModel.get());
 	ui.TableDB->setItemDelegate(new bookEditDelegate(Impl->tableModel.get()->fieldIndex("locked"),this));
	ui.TableDB->setColumnHidden(Impl->tableModel->fieldIndex("mov_id"), true);
	ui.TableDB->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TableDB->setSortingEnabled(true);

	ui.buttonDelRow->setEnabled(false);

	
}

bookEdit::~bookEdit() {
	
}

void bookEdit::deleteCurrentRow()
{
	emit sendRowIndexToBeDeleted(ui.TableDB->currentIndex().row());
}

void bookEdit::toggleDeleteButton(int state)
{
	ui.buttonDelRow->setEnabled(state);
}


