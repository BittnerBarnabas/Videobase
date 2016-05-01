#pragma once
#include <QAbstractItemView>
#include <QDataWidgetMapper>
#include <QTableView>
#include <QWidget>
#include <QSqlQuery>
#include <memory>
#include "Implementation/rentaleditimpl.h"
#include "rentaleditingdelegate.h"
#include "ui_rentalediting.h"

namespace View {
	/*!
	 * \class rentalEditing
	 *
	 * \brief Provides the interface for displaying and editing the rentals. 
	 *
	 * \author barni
	 *
	 * \version 1.0
	 *
	 * \date April 2016
	 *
	 *
	 *
	 */
class rentalEditing : public QWidget {
  Q_OBJECT

 public:
  rentalEditing(QWidget* parent = Q_NULLPTR);
  ~rentalEditing();

 private:
  void setUpTableView();  //!< Sets up the initial view
  void setUpMovieTitleEditCombo();
  std::unique_ptr<Implementation::rentalEditImpl>
      Model;  //!< Stores the model of this view
  Ui::rentalEditing ui;
};
}
