#include "modi_dialog.h"
#include "ui_modi_dialog.h"
#include "common.h"

modi_dialog::modi_dialog(QSqlQuery & q,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modi_dialog),
    q(q)
{
    ui->setupUi(this);
    init_db(db);
	QMessageBox::information(this,"success",q.executedQuery());
}

modi_dialog::~modi_dialog()
{
    delete ui;
}

//submit
void modi_dialog::on_pushButton_clicked(){
	QString data = ui->lineEdit->text();
	QMessageBox::information(this,"success",q.executedQuery());

	q.bindValue(":data",data);
	if(q.exec()){
		QMessageBox::information(this,"success","sucess to update data");
	}
	else{
		QMessageBox::information(this,"fail","fail to update data");
	}
}

void modi_dialog::on_pushButton_2_clicked(){

}