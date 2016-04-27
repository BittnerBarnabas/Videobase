#pragma once
#include <QWidget>
#include <QTableView>
#include "ui_rentalediting.h"

namespace View
{
	class rentalEditing : public QWidget {
		Q_OBJECT
	
	public:
		rentalEditing(QWidget * parent = Q_NULLPTR);
		~rentalEditing();
	
	private:
		Ui::rentalEditing ui;
	};
}
