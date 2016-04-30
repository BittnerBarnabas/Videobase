#pragma once
#include <QWidget>
#include <QTableView>
#include <memory>
#include "Implementation/rentaleditimpl.h"
#include "ui_rentalediting.h"
#include "rentaleditingdelegate.h"

namespace View
{
	class rentalEditing : public QWidget {
		Q_OBJECT
	
	public:
		rentalEditing(QWidget * parent = Q_NULLPTR);
		~rentalEditing();
	
	private:
		std::unique_ptr<Implementation::rentalEditImpl> Model;
		Ui::rentalEditing ui;
	};
}
