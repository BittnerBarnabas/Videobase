#include "movieEditImpl.h"

namespace Implementation
{
	void movieEditImpl::insertRowToEnd()
	{
		tableModel->insertRow(tableModel->rowCount());
	}

	void movieEditImpl::toggleRentable(int state)
	{
		if (state) 	tableModel->setFilter("mov_id not in(select mov_id from rentals where RET_DATE = '0000-00-00') and locked is false");
		else tableModel->setFilter("");
		tableModel->select();
	}

	void movieEditImpl::toggleRented(int state)
	{
		if (state) 	tableModel->setFilter("mov_id in(select mov_id from rentals where RET_DATE = '2001-01-01')");
		else tableModel->setFilter("");
		tableModel->select();
	}

	void movieEditImpl::deleteCurrentRow(int Ind)
	{
		tableModel->removeRow(Ind);
	}

	void movieEditImpl::revertAll()
	{
		tableModel->revertAll();
		tableModel->select();
	}

	void movieEditImpl::submitAll()
	{
		if (!tableModel->submitAll())
			QMessageBox::information(nullptr, "Couldn't submit changes", tableModel->lastError().text());

	}
}