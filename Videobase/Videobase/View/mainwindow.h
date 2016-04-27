#pragma once
#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include "View/MovieEdit.h"
#include "View/rentalediting.h"
#include <memory>
namespace Ui {class MainWindow;}
namespace View
{
	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow(QWidget * parent = Q_NULLPTR);
		~MainWindow();
	public slots:
		void editMovies();
		void editRentals();
	private:
		std::unique_ptr<Ui::MainWindow> ui;
		std::unique_ptr<MovieEdit> movieEditWidget;
		std::unique_ptr<rentalEditing> rentalEditingWidget;
	};
}