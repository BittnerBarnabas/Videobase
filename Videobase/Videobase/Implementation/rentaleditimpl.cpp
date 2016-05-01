#include "rentaleditimpl.h"

namespace Implementation {

rentalEditImpl::~rentalEditImpl() {}

void rentalEditImpl::updateTitle(int rowNum, int movId)
{
	tableModel->setData(tableModel->index(rowNum, 2), movId);
}

void rentalEditImpl::returnMovie(int rowNum)
{
	tableModel->setData(tableModel->index(rowNum, tableModel->fieldIndex("ret_date")), currentDateToString());
}

QString rentalEditImpl::currentDateToString() {
  auto currD = QDate::currentDate();
  int Y = currD.year();
  int M = currD.month();
  int D = currD.day();
  return QString(QString::number(Y) + "-" + QString::number(M) + "-" +
                 QString::number(D));
}

void rentalEditImpl::insertRowToEnd() {
  tableModel->insertRow(tableModel->rowCount());
  tableModel->setData(tableModel->index(tableModel->rowCount() - 1, tableModel->fieldIndex("rent_date")),
                      currentDateToString());
}
}
