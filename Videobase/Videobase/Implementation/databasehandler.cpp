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
