#include <QtSql>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include <memory>

namespace SQLStorage
{
	void createSqlConnection();
	std::unique_ptr<QSqlRelationalTableModel> createSQLModel();
	std::unique_ptr<QSqlRelationalTableModel> createBookeditModel();
	void insertRowToDB(QSqlRelationalTableModel* model,int afterPos);
}