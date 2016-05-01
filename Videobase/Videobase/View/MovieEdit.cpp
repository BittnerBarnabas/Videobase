#include "MovieEdit.h"
#include "movieEditDelegate.h"
namespace View
{
	MovieEdit::MovieEdit(QWidget * parent) : QWidget(parent), Model(std::make_unique<Implementation::bookEditImpl>())
	{
		ui.setupUi(this);
	
		connect(ui.buttonSubmit, SIGNAL(clicked()), Model.get(), SLOT(submitAll()));
		connect(ui.buttonRevert, SIGNAL(clicked()), Model.get(), SLOT(revertAll()));
		connect(ui.buttonNewRow, SIGNAL(clicked()), Model.get(), SLOT(insertRowToEnd()));
		connect(ui.buttonDelRow, SIGNAL(clicked()), this, SLOT(deleteCurrentRow()));
		connect(ui.checkBoxRentableToggle, SIGNAL(stateChanged(int)), Model.get(), SLOT(toggleRentable(int)));
		connect(ui.checkBoxRentedToggle, SIGNAL(stateChanged(int)), Model.get(), SLOT(toggleRented(int)));
		connect(ui.checkBoxRentableToggle, SIGNAL(stateChanged(int)), this, SLOT(toggleDeleteButton(int)));
		connect(this, SIGNAL(sendRowIndexToBeDeleted(int)), Model.get(), SLOT(deleteCurrentRow(int)));
	
		ui.TableDB->setModel(Model->tableModel.get());
	 	ui.TableDB->setItemDelegate(new movieEditDelegate(Model->tableModel.get()->fieldIndex("locked"),this));
		ui.TableDB->setColumnHidden(Model->tableModel->fieldIndex("mov_id"), true);
		ui.TableDB->setSelectionBehavior(QAbstractItemView::SelectRows);
		ui.TableDB->setSortingEnabled(true);
	
		ui.buttonDelRow->setEnabled(false);
	
		
	}
	
	MovieEdit::~MovieEdit() {
		
	}
	
	void MovieEdit::deleteCurrentRow()
	{
		emit sendRowIndexToBeDeleted(ui.TableDB->currentIndex().row());
	}
	
	void MovieEdit::toggleDeleteButton(int state)
	{
		ui.buttonDelRow->setEnabled(state);
	}
}


