#include "login.h"
#include "ui_login.h"
#include "maingui.h"
#include "common.h"



login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
//qDebug()<<"run set up ui";
    ui->setupUi(this);

    init_db(db);

    //test_func();
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
	// input username
	QString l_username = ui->lineEdit->text();
	// input password
	QString l_password = ui->lineEdit_2->text();

	QSqlQuery q;
	QString sql = "select password from userinfo where username = :id" ;
	q.prepare(sql);
	q.bindValue(":id","123");
	if (!q.exec()){

	}
	else {
		q.next();
		QString d_password = q.value(0).toString();

		if(l_password == d_password){

			//mainGui widget 
			mainGui * w = new mainGui;
			w-> show();
			this->close();
		}
	}


}


void login::test_func(){
	on_pushButton_clicked();
}
