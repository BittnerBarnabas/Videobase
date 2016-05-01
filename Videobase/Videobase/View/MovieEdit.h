#pragma once
#include <QWidget>
#include "ui_movieedit.h"
#include <memory>
#include <QSql>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include "Implementation/databasehandler.h"
#include "Implementation/movieEditImpl.h"
namespace View
{
/*!
 * \class MovieEdit
 *
 *
 * \brief This is responsible for displaying the interface for editing movies
 *
 * TODO: long description
 *
 *
 *
 * \author barni
 *
 * \version 1.0
 *
 * \date April 2016
 *
 * Contact: bittnerbarni@gmail.com
 *
 */
	class MovieEdit : public QWidget
	{
		Q_OBJECT
	public:
		MovieEdit(QWidget * parent = Q_NULLPTR);
		~MovieEdit();
		public slots:
		void deleteCurrentRow(); //!< Slot to signal the deletion of the currently selected row
		void toggleDeleteButton(int state); //!< Enables/disables the delete button
	signals:
		void sendRowIndexToBeDeleted(int ind); //!< This is sent by @deleteCurrentRow
	private:
		Ui::movieEdit ui; //!< Contains the additional UI of the class
		std::unique_ptr<Implementation::movieEditImpl> Model; //!< QT model for storing SQL information
	};
}