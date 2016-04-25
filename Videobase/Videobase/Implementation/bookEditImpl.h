#pragma once
#include <QSqlRelationalTableModel>
#include <QSql>
#include <memory>
#include "databasehandler.h"


namespace Implementation
{
	class bookEditImpl : public QObject
	{
		Q_OBJECT;
	public:
		std::unique_ptr<QSqlRelationalTableModel> tableModel; //!< QT model for connecting SQL and View
		bookEditImpl() : tableModel(SQLStorage::createBookeditModel()){}
		public slots:
		void insertRowToEnd(); //!< Inserts a row to the end of the table
		void toggleRentable(int state); //!< Toggles the display of only the rentable movies
		void toggleRented(int state);
		void deleteCurrentRow(int Ind);
		void revertAll();
		void submitAll();
	};
}