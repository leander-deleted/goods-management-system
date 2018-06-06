#include "query.h"
#include "ui_query.h"
#include "common.h"

query::query(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::query)
{
    ui->setupUi(this);
    ui->precisionGroup->setId(ui->precise,0);
    ui->precisionGroup->setId(ui->vague,1);
    init_db(db);
}

query::~query()
{
    delete ui;
}

// submit to search 
void query::on_pushButton_clicked(){
	QString queryWord = ui->queryWord->text();

	// selected button id, id=0, precision; id=1, vague
	int id = ui->precisionGroup->checkedId();
	
	QString c_queryType = ui->comboBox->currentText();
	QSqlQuery q;
	QString sql;
	if(c_queryType=="按商品名称"){

//QMessageBox::information(this,"success",queryWord);
		if(id==0){
			/*
		select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment
		 from all_show_info 
		 where  goodsname = :goodsname;

			*/
		sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
		" from all_show_info "
		" where  goodsname = :goodsname";
		}
		else if(id==1){
			sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
		" from all_show_info "
		" where goodsname like :c :goodsname :c";
		}
		q.prepare(sql);
		q.bindValue(":c","%");
		q.bindValue(":goodsname",queryWord);
	} else if (c_queryType == "按进货/出货"){
			sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
		" from all_show_info "
		" where ei like :c :ei :c";
		q.prepare(sql);
		q.bindValue(":c","%");
		q.bindValue(":ei",queryWord);
		}
		else if (c_queryType == "按联系人"){
		if(id==0){

			/*
			 select eiinfo.goodsname,ei,eiinfo.contact,source,place,number,price,catogory,tel,apartment
			 from eiinfo,goodsinfo,contact 
			 where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact
			 and  contact.contact = :contact


			*/
			sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where  contact = :contact";
		}
		else if(id==1){
				sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where contact like :c :contact :c";
		}
			q.prepare(sql);
			q.bindValue(":c","%");
			q.bindValue(":contact",queryWord);
	}
	else if (c_queryType == "按产地"){
		if(id==0){
			sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where  source = :source";
		}
		else if(id==1){
				sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where source  like :c :source :c";
		}
			q.prepare(sql);
			q.bindValue(":c","%");
			q.bindValue(":source",queryWord);
	}
	else if (c_queryType == "按交易地点"){
		if(id==0){
			sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where  place = :place";
		}
		else if(id==1){
				sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where place  like :c :place :c";
		}
			q.prepare(sql);
			q.bindValue(":c","%");
			q.bindValue(":place",queryWord);
	}
	else if (c_queryType == "按交易单位"){
		if(id==0){
			sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where  apartment = :apartment";
		}
		else if(id==1){
			/*
			 select eiinfo.goodsname,ei,eiinfo.contact,source,place,number,price,catogory,tel,apartment
			 from eiinfo,goodsinfo,contact 
			 where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact
			 and contact.apartment  like "%厂%"
			*/
				sql = "select goodsname,ei,contact,source,place,number,price,catogory,tel,apartment"
			" from all_show_info "
			" where apartment  like :c :apartment :c";
		}
			q.prepare(sql);
			q.bindValue(":c","%");
			q.bindValue(":apartment",queryWord);
	}


		if(q.exec()){
//QMessageBox::information(this,"success","sucessfully query get data");

		//row index
		int i = 0;

		int rowCount = 0;
		if(q.last()){
			rowCount = q.at()+1;
			q.first();
			q.previous();
		}
		ui->tableWidget->setRowCount(rowCount);
		ui->tableWidget->setColumnCount(10);

		QStringList h_header;
		QStringList records;
		h_header << "产品名称"<<"进口/出口"<<"交易地点"<<"产地"<<"数量"<<"价格"<<"种类"<<"交易联系人"<<"联系人电话"<<"交易单位";
		ui->tableWidget->setHorizontalHeaderLabels(h_header);
		ui->tableWidget->verticalHeader()->setVisible(true);
		while(q.next()){
			QString goodsname = q.value(0).toString();
			QString ei = q.value(1).toString();
			QString contact = q.value(2).toString();
			QString source = q.value(3).toString();
			QString place = q.value(4).toString();
			QString number = q.value(5).toString();
			QString price = q.value(6).toString();
			QString catogory = q.value(7).toString();
			QString tel = q.value(8).toString();
			QString apartment = q.value(9).toString();
			records<<goodsname<<ei<<place<<source<<number<<price<<catogory<<contact<<tel<<apartment;
			//column index
			int j = 0;
			while (j<10){
				ui->tableWidget->setItem(i,j,new QTableWidgetItem(records.at(j)));
				j++;
			}
			records.clear();
			i++;
		}
		}
		else{
	//QString t ("there %1 are");
			if(id==-1){
				QMessageBox::information(this,"fail","请选择搜索类型");
			}
			else{
				QMessageBox::information(this,"fail","fail to query data");
			}
		}
}


