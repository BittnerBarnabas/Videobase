#pragma once
#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <memory>
namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget * parent = Q_NULLPTR);
	~MainWindow();
	void populateDBTable();
private:
	std::unique_ptr<Ui::MainWindow> ui;
	std::unique_ptr<QSqlRelationalTableModel> tableModel; //!< QT model for connecting SQL and View
};
