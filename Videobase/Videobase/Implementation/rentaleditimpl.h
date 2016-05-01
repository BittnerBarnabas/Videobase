#pragma once
#include <QObject>
#include <QSqlRelationalTableModel>
#include <QDate>
#include <memory>
#include "databasehandler.h"

namespace Implementation {
class rentalEditImpl : public QObject {
  Q_OBJECT
 public:
  std::unique_ptr<QSqlRelationalTableModel> tableModel;
  rentalEditImpl(QObject* parent = Q_NULLPTR)
      : tableModel(SQLStorage::createRentalEditModel()) {}
  ~rentalEditImpl();
 public slots:
  void insertRowToEnd();
  void updateTitle(int rowNum, int movId);
  void returnMovie(int rowNum);
private:
	QString currentDateToString();
};
}
