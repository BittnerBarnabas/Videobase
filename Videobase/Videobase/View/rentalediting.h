#pragma once
#include <QAbstractItemView>
#include <QDataWidgetMapper>
#include <QTableView>
#include <QWidget>
#include <memory>
#include "Implementation/rentaleditimpl.h"
#include "rentaleditingdelegate.h"
#include "ui_rentalediting.h"

namespace View {
class rentalEditing : public QWidget {
  Q_OBJECT

 public:
  rentalEditing(QWidget* parent = Q_NULLPTR);
  ~rentalEditing();
  void setUpTableView();

 private:
  std::unique_ptr<Implementation::rentalEditImpl> Model;
  Ui::rentalEditing ui;
};
}
