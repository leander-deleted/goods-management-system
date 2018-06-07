#include "maingui.h"
#include "ui_maingui.h"
#include "input.h"
#include "result.h"
#include "query.h"

mainGui::mainGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainGui)
{
    ui->setupUi(this);
    this->resize(800,600);
}

mainGui::~mainGui()
{
    delete ui;
}

// input button
void mainGui::on_pushButton_clicked(){

	input * w = new input;
	w->show();

}

// print preview
void mainGui::on_pushButton_3_clicked(){

	result * w = new result;
	w->show();

}

// query
void mainGui::on_pushButton_4_clicked(){

	query * w = new query;
	w->show();

}

//backup
void mainGui::on_pushButton_5_clicked(){
	system("mysqldump --defaults-extra-file=C:/mysql/idconfig.conf a2 > backup.sql");
	std::fstream sql_file("./backup.sql");
	sql_file.seekg(0,std::ios::end);
	int size = sql_file.tellg();
	if(size!=0){
		QMessageBox::information(this,"success","back up successfully");
	}
	else{
		QMessageBox::information(this,"fail","fail to backup");
	}
}