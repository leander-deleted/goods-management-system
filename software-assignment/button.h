#ifndef BUTTON_H
#define BUTTON_H

#include<QPushButton>
#include<QTableWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<qDebug>
#include"result.h"

class Button: public QPushButton{

	Q_OBJECT

public:
	explicit Button(QString text, result * r,QWidget*parent=0);


private slots:
	void del_data();

private:
	QPushButton * button;
	QSqlDatabase db;
	result * r;
};

#endif