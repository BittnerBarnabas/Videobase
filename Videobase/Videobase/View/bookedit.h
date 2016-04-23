#pragma once
#include <QWidget>
#include "ui_bookedit.h"
#include <memory>
#include <QSql>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include "Implementation/databasehandler.h"
#include "Implementation/bookEditImpl.h"

class bookEdit : public QWidget {
	Q_OBJECT

public:
	bookEdit(QWidget * parent = Q_NULLPTR);
	~bookEdit();
// 	inline Ui::bookEdit* getUi(){ return &ui; }

	public slots:
	void deleteCurrentRow();
	void toggleDeleteButton(int state);
signals:
	void sendRowIndexToBeDeleted(int ind);
private:
	Ui::bookEdit ui;
	std::unique_ptr<Implementation::bookEditImpl> Impl; //!< QT model for connecting SQL and View


};
