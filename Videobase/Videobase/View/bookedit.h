#pragma once
#include <QWidget>
#include "ui_bookedit.h"
#include <memory>
#include <QSql>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include "Implementation/databasehandler.h"

class bookEdit : public QWidget {
	Q_OBJECT

public:
	bookEdit(QWidget * parent = Q_NULLPTR);
	~bookEdit();
// 	inline Ui::bookEdit* getUi(){ return &ui; }

	public slots:
	void insertRowToEnd();

private:
	Ui::bookEdit ui;
	std::unique_ptr<QSqlRelationalTableModel> tableModel; //!< QT model for connecting SQL and View


};
