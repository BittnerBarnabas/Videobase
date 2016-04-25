#include "bookEditImpl.h"

namespace Implementation
{
	void bookEditImpl::insertRowToEnd()
	{
		tableModel->insertRow(tableModel->rowCount());
	}

	void bookEditImpl::toggleRentable(int state)
	{
		if (state) 	tableModel->setFilter("mov_id not in(select mov_id from rentals where RET_DATE = '0000-00-00') and locked is false");
		else tableModel->setFilter("");
		tableModel->select();
	}

	void bookEditImpl::toggleRented(int state)
	{
		if (state) 	tableModel->setFilter("mov_id in(select mov_id from rentals where RET_DATE = '0000-00-00')");
		else tableModel->setFilter("");
		tableModel->select();
	}

	void bookEditImpl::deleteCurrentRow(int Ind)
	{
		tableModel->removeRow(Ind);
	}

	void bookEditImpl::revertAll()
	{
		tableModel->revertAll();
		tableModel->select();
	}

	void bookEditImpl::submitAll()
	{
		if (!tableModel->submitAll())
			QMessageBox::information(nullptr, "Couldn't insert row", tableModel->lastError().text());

	}
}