#include "rentaleditimpl.h"

namespace Implementation {

rentalEditImpl::~rentalEditImpl() {}

QString rentalEditImpl::currentDateToString() {
  auto currD = QDate::currentDate();
  int Y = currD.year();
  int M = currD.month();
  int D = currD.day();
  return QString(QString::number(M) + "/" + QString::number(D) + "/" +
                 QString::number(Y));
}

void rentalEditImpl::insertRowToEnd() {
  tableModel->insertRow(tableModel->rowCount());
  tableModel->setData(tableModel->index(tableModel->rowCount() - 1, 3),
                      currentDateToString());
}
}
