#include "databasehandler.h"

void SQLStorage::createSqlConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("videobase");
	db.setUserName("barni");
	db.setPassword("mamacica");
	if (!db.open())
	{
		QMessageBox Msgbox;
		Msgbox.setText(db.lastError().text());
		Msgbox.exec();
	}

}

std::unique_ptr<QSqlRelationalTableModel> SQLStorage::createSQLModel()
{
	auto model = std::make_unique<QSqlRelationalTableModel>();
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	return model;
}

std::unique_ptr<QSqlRelationalTableModel> SQLStorage::createBookeditModel()
{
	auto model = createSQLModel();
	model->setTable("movies");

	model->setHeaderData(model->fieldIndex("title"), Qt::Horizontal,
							  "Title");
	model->setHeaderData(model->fieldIndex("main_char"), Qt::Horizontal,
							  "Main characters");
	model->setHeaderData(model->fieldIndex("director"), Qt::Horizontal,
							  "Director");
	model->setHeaderData(model->fieldIndex("publisher"), Qt::Horizontal,
							  "Publisher");
	model->setHeaderData(model->fieldIndex("year"), Qt::Horizontal,
							  "Year");
	model->setHeaderData(model->fieldIndex("locked"), Qt::Horizontal,
							  "Is it locked");

	model->select();
	return model;
}

std::unique_ptr<QSqlRelationalTableModel> SQLStorage::createRentalEditModel()
{
	auto model = createSQLModel();
	model->setTable("rentals");
	model->setRelation(model->fieldIndex("mov_id"), QSqlRelation("movies", "mov_id", "title"));
	model->setRelation(model->fieldIndex("mem_id"), QSqlRelation("members", "mem_id", "name"));

	model->setHeaderData(model->fieldIndex("mov_id"), Qt::Horizontal, "Movie title");
	model->setHeaderData(model->fieldIndex("mem_id"), Qt::Horizontal, "Member name");
	model->setHeaderData(model->fieldIndex("rent_date"), Qt::Horizontal, "Rental date");
	model->setHeaderData(model->fieldIndex("ret_date"), Qt::Horizontal, "Return date");

	model->select();

	return model;
	
}

void SQLStorage::insertRowToDB(QSqlRelationalTableModel* model,int afterPos)
{
	model->insertRow(afterPos);
}
