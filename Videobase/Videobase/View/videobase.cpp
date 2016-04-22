#include "videobase.h"
#include "Implementation/databasehandler.h"

Videobase::Videobase(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
	SQLStorage::createSqlConnection();
}

Videobase::~Videobase() {
	
}
