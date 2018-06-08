#include "input.h"
#include "ui_input.h"
#include "login.h"
#include "common.h"

bool insert_db(QStringList &sql_list,int order,QStringList&data_list,int number,int price);

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

	QStringList sql_l_1,sql_l_2,sql_l_3;

	QStringList data_list;
	data_list<<catogory<<EI<<nameProduct<<size<<source<<place<<apartAddr<<contactName<<contactTel;

	/*
	insert into contact(contact,tel,apartment) 
	values("老王","124124","m102")
	*/
	

	sql_l_1<<"lock table contact write"
	<<"insert into contact(contact,tel,apartment) values(:contact,:tel,:apartment)"
	<<"unlock tables";

		
	/*
	insert into goodsinfo(goodsname,contact,source,place,number,price,catogory) 
	values("线性代数","老刘","m楼","n楼",400,4.3,"金属材料");

	insert into goodsinfo(goodsname,contact,source,place,number,price,catogory) 
	values("钢铁","李珊珊","沈阳","大连",400,4.3,"金属材料");
	*/

	sql_l_2<<"lock table goodsinfo write"
	<< "insert into goodsinfo(goodsname,contact,source,place,number,price,catogory) values(:name,:contact,:source,:place,:number,:price,:catogory)"
	<<"unlock tables";
	

	sql_l_3<<"lock table eiinfo write"
	<<"insert into eiinfo(goodsname,contact,ei) values(:goodsname,:contact,:ei)"
	<<"unlock tables";

	int i =0;
	while(i<3){
		if(i==0){

			if(insert_db(sql_l_1,1,data_list,number,price)){
				//ok
			}
			else{
				QMessageBox::information(this,"fail","input error");
			}
		}
		else if (i==1){
			if(insert_db(sql_l_1,1,data_list,number,price)){
				//ok
			}
			else{
				QMessageBox::information(this,"fail","input error");
			}
		}
		else{
			if(insert_db(sql_l_1,1,data_list,number,price)){
				//ok
			}
			else{
				QMessageBox::information(this,"fail","input error");
			}
		}
		i++;
	}
	on_pushButton_2_clicked();
}


bool insert_db(QStringList &sql_list,int order,QStringList&data_list,int number,int price){
	QSqlQuery q;
	int i =0;
	bool flag = true;
	for(QString sql:sql_list){
		q.prepare(sql);
		if(i==1){
			if(order==1){
				q.bindValue(":contact",data_list.at(7));
				q.bindValue(":tel",data_list.at(8));
				q.bindValue(":apartment",data_list.at(6));
			}
			else if (order == 2){
				q.bindValue(":name",data_list.at(2));
				q.bindValue(":contact",data_list.at(7));
				q.bindValue(":source",data_list.at(4));
				q.bindValue(":place",data_list.at(5));
				q.bindValue(":number",number);
				q.bindValue(":price",price);
				q.bindValue(":catogory",data_list.at(0));
			}
			else if (order ==3){
				q.bindValue(":goodsname",data_list.at(2));
				q.bindValue(":contact",data_list.at(7));
				q.bindValue(":ei",data_list.at(1));
			}
		}

		if(q.exec()){
			//lock/unlock successfully
		}
		else{
			//lock/unlock fail
			flag = false;
		}
	}
	i++;
	return flag;
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