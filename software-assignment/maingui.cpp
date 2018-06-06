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
    this->resize(800,483);
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