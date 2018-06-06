#include "input.h"
#include "ui_input.h"
#include "login.h"
#include "common.h"


input::input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
    this->resize(900,730);
    init_db(db);
}

input::~input()
{
    delete ui;
}

//submit 
void input::on_pushButton_clicked(){
	QString catogory = ui->comboBox->currentText();
	QString EI = ui->comboBox_3->currentText();
	//name of goods
	QString nameProduct = ui->lineEdit_9->text();
	QString size = ui->comboBox_2->currentText();
	QString source = ui->lineEdit_8->text();
	QString place = ui->lineEdit_7->text();
	int number = ui->lineEdit_6->text().toInt();
	float price = ui->lineEdit_5->text().toFloat();
	QString apartAddr = ui->lineEdit->text();
	QString contactName = ui->lineEdit_2->text();
	QString contactTel = ui->lineEdit_3->text();

	QSqlQuery q ;
	QString sql;
	/*
	insert into contact(contact,tel,apartment) 
	values("老王","124124","m102")
	*/
	sql = "insert into contact(contact,tel,apartment) values(:contact,:tel,:apartment)";
	q.prepare(sql);
	q.bindValue(":contact",contactName);
	q.bindValue(":tel",contactTel);
	q.bindValue(":apartment",apartAddr);

	if(q.exec()){

		/*
		insert into goodsinfo(goodsname,contact,source,place,number,price,catogory) 
		values("线性代数","老刘","m楼","n楼",400,4.3,"金属材料");

		insert into goodsinfo(goodsname,contact,source,place,number,price,catogory) 
		values("钢铁","李珊珊","沈阳","大连",400,4.3,"金属材料");
		*/
		sql = "insert into goodsinfo(goodsname,contact,source,place,number,price,catogory) values(:name,:contact,:source,:place,:number,:price,:catogory)";
		q.prepare(sql);
		q.bindValue(":name",nameProduct);
		q.bindValue(":contact",contactName);
		q.bindValue(":source",source);
		q.bindValue(":place",place);
		q.bindValue(":number",number);
		q.bindValue(":price",price);
		q.bindValue(":catogory",catogory);
		if(q.exec()){

		}
		else{
		QMessageBox::information(this,"提示","联系人已存在");
		}
		sql = "insert into eiinfo(goodsname,contact,ei) values(:goodsname,:contact,:ei)";
			q.prepare(sql);
			q.bindValue(":goodsname",nameProduct);
			q.bindValue(":contact",contactName);
			q.bindValue(":ei",EI);
			if(q.exec()){
				QMessageBox::information(this,"success","sucessfully add into db");
			}
			else{
			QMessageBox::information(this,"fail","fail to add eiinfo into db");
			}
	}
	else{
		QMessageBox::information(this,"fail","fail to add goods info into db");
	}
	on_pushButton_2_clicked();
	
}

//clear
void input::on_pushButton_2_clicked(){
	ui->lineEdit_9->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_8->clear();
	ui->lineEdit_7->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit->clear();
	ui->lineEdit_3->clear();
}
/*
void setModiUi(QString goodsname="",QString ei="",QString contact=""){
	QSqlQuery q ;
	QString sql = "select eiinfo.goodsname,ei,eiinfo.contact,source,place,number,price,catogory,tel,apartment"
		" from eiinfo,goodsinfo,contact "
		" where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact"
		" and eiinfo.contact = :contact and goodsinfo.goodsname=:goodsname and eiinfo.ei = :ei"
	q.prepare(sql);
	q.bindValue(":goodsname",goodsname);
	q.bindValue(":contact",contactName);
	q.bindValue(":ei",ei);
	if(q.exec()){
		QString catogory = q.value(7).toString();
		QString EI = q.value(7).toString();
		//name of goods
		QString nameProduct = q.value(7).toString();
		QString size = q.value(7).toString();
		QString source = q.value(7).toString();
		QString place = q.value(7).toString();
		QString number = q.value(7).toString();
		QString price = q.value(7).toString();
		QString apartAddr = q.value(7).toString();
		QString contactName = q.value(7).toString();
		QString contactTel = q.value(7).toString();

	}


}
	*/