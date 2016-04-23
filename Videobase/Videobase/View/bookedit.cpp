#include "bookedit.h"

bookEdit::bookEdit(QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);
	tableModel = SQLStorage::createBookeditModel();


	connect(ui.buttonSubmit, SIGNAL(clicked()), tableModel.get(), SLOT(submitAll()));
	connect(ui.buttonRevert, SIGNAL(clicked()), tableModel.get(), SLOT(revertAll()));
	connect(ui.buttonNewRow, SIGNAL(clicked()), this, SLOT(insertRowToEnd()));


	ui.TableDB->setModel(tableModel.get());
	ui.TableDB->setItemDelegate(new QSqlRelationalDelegate(ui.TableDB));
	ui.TableDB->setColumnHidden(tableModel->fieldIndex("mov_id"), true);
	ui.TableDB->setSelectionBehavior(QAbstractItemView::SelectRows);
}

bookEdit::~bookEdit() {
	
}

void bookEdit::insertRowToEnd()
{
	tableModel->insertRow(tableModel->rowCount());
}
