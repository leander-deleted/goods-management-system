#include "common.h"



void init_db(QSqlDatabase & db){

	db = QSqlDatabase::addDatabase("QMYSQL");

	db.setDatabaseName("a2");
	db.setHostName("localhost");
	db.setUserName("root");
	db.setPassword("277435");

	if(!db.open()){
		qDebug("fail");
	}
	qDebug()<<"connect to mysql server";

}
