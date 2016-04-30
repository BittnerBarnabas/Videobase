#include "rentaleditimpl.h"

namespace Implementation {

rentalEditImpl::~rentalEditImpl() {}

void rentalEditImpl::insertRowToEnd() {
  tableModel->insertRow(tableModel->rowCount());
}
}
