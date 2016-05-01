#pragma once
#include <QAbstractItemView>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QTableView>
#include <QWidget>
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
 signals:
  void titleFromCombobox(int rowNum, int movId);
  void returnMovieInRow(int rowNum);
 public slots:
  void submitAll();  //!< Submits the changes, displays messagebox if there were
                     //!an error
  void sendTitleFromCombobox(int ind);  //!< Helper function to send the
                                        //!currently selected movie id from the
                                        //!title editing combobox
  void sendReturnMovieInRow();
 private:
  void setUpTableView();            //!< Sets up the initial view
  void setUpMovieTitleEditCombo();  //!< Sets up the Title editing combobox
  std::unique_ptr<Implementation::rentalEditImpl>
      Model;  //!< Stores the model of this view
  Ui::rentalEditing ui;
};
}
