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

}

login::~login()
{
    delete ui;
}

//submit 
void login::on_pushButton_clicked()
{
	// input username
	QString l_username = ui->lineEdit->text();
	// input password
	QString l_password = ui->lineEdit_2->text();

	QSqlQuery q;
	QString sql = "select password from userinfo where username = :id" ;
	q.prepare(sql);
	q.bindValue(":id",l_username);
	if (!q.exec()){
		QMessageBox::warning(this,"fail","用户不存在");
	}
	else {
		q.next();

		//password get from database
		QString d_password = q.value(0).toString();

		if(l_password == d_password){

			//mainGui widget 
			mainGui * w = new mainGui;
			w-> show();
			this->close();
		}
		else{
			QMessageBox::warning(this,"fail","密码错误或用户不存在");
		}
	}


}


void login::on_pushButton_2_clicked(){
	ui->lineEdit->clear();
	ui->lineEdit_2->clear();
}

void login::test_func(){
	on_pushButton_clicked();
}
