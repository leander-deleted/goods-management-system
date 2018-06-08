#include "result.h"
#include "ui_result.h"
#include "common.h"
#include "modi_dialog.h"
#include "button.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    ui->verticalLayout->setStretch(1,2);
    ui->verticalLayout->addWidget(ui->pushButton);
    this->setLayout(ui->verticalLayout);

    init_db(db);
    show_result();
    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doubleClick(int,int)));
    connect(this,SIGNAL(refresh()),this,SLOT(show_refresh()));
 	//QMessageBox::information(this,"success","open result cpp");
   
}

result::~result()
{
    delete ui;
}

void result::emitSignal(){
	emit refresh();
}

// version 1
/*
void show_result_v1(){
	QSqlQuery q;
	QString sql;
	
	select eiinfo.goodsname,ei,eiinfo.contact,source,place,number,price,catogory,tel,apartment
	from eiinfo,goodsinfo,contact 
	where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact;
	
	sql = "select eiinfo.goodsname,ei,eiinfo.contact,source,place,number,price,catogory,tel,apartment"
		" from eiinfo,goodsinfo,contact "
		" where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact";
	q.prepare(sql);
	if(q.exec()){
		//QMessageBox::information(this,"success","sucessfully query get data");
		//row index
		int i = 0;
		int j = 0;
		int rowCount = 0;
		if(q.last()){
			rowCount = q.at()+1;
			q.first();
			q.previous();
		}
		//QMessageBox::information(this,"success",QString::number(rowCount));		
		ui->tableWidget->setRowCount(rowCount);
		ui->tableWidget->setColumnCount(11);

		QStringList h_header;
		QStringList records;
		h_header <<"产品名称"<< "进口/出口"<<"交易地点"<<"产地"<<"数量"<<"价格"<<"种类"<<"交易联系人"<<"联系人电话"<<"交易单位"<<"按钮";
		ui->tableWidget->setHorizontalHeaderLabels(h_header);
		ui->tableWidget->verticalHeader()->setVisible(true);
		while(q.next()){
            qDebug()<<"fetch one record";
            //QMessageBox::information(this,"success",QString::number(1));
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
			j = 0;
			while (j<10){
				ui->tableWidget->setItem(i,j,new QTableWidgetItem(records.at(j)));
				j++;
			}
			ui->tableWidget->setCellWidget(i,j,new Button("删除",this));
			records.clear();
			i++;
		}
	}
*/

void result::show_result(){
	QSqlQuery q;
	QString sql;

	//apartment list
	QStringList apt_list;

	//ei list
	QStringList ei_list;

	ei_list<<"进货"<<"出货";

	// stores a row of data
	QStringList records;

	ui->tableWidget->setRowCount(20);
	ui->tableWidget->setColumnCount(11);
	QStringList h_header;
	h_header <<"产品名称"<< "进口/出口"<<"交易地点"<<"产地"<<"数量"<<"价格"<<"种类"<<"交易联系人"<<"联系人电话"<<"交易单位"<<"按钮";
	ui->tableWidget->setHorizontalHeaderLabels(h_header);
	ui->tableWidget->verticalHeader()->setVisible(true);

	/*
		select apartment from goodsinfo,contact where goodsinfo.contact = contact.contact
	*/
	sql = "select distinct apartment from goodsinfo,contact where goodsinfo.contact = contact.contact ";
	q.prepare(sql);

	//the sum of row count
	//int rowCount = 0;

	qDebug()<<"successfully run show_result() function";	

	//execute select apartment
	if(q.exec()){
		int i = 0;
		int j = 0;

		//qDebug()<<"successfully get apartment list";	
		while(q.next()){
			apt_list<<q.value(0).toString();
		}

		//qDebug()<<"apt_list : "<<apt_list;
		for(QString ei:ei_list){

			//qDebug()<<ei;
			for(QString apt : apt_list){

				//qDebug()<<apt<<"is running";
				/*
				select eiinfo.goodsname,eiinfo.contact,source,place,number,price,catogory,tel
				from eiinfo,goodsinfo,contact 
				where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact
				 and apartment="石灰厂" ;
				*/

				/*
				select goodsname,contact,source,place,number,price,catogory,tel
				 from all_show_info
				 and ei= "进货" and apartment = "鲨鱼厂"
				*/
				sql = "select goodsname,contact,source,place,number,price,catogory,tel"
					" from all_show_info"
				" where ei= :ei and apartment = :apt";
				q.prepare(sql);
				q.bindValue(":apt",apt);
				q.bindValue(":ei",ei);
				bool flag = true;
				if(q.exec()){
					while(q.next()){
			            //qDebug()<<"fetch one record";
			            //QMessageBox::information(this,"success",QString::number(1));
						QString goodsname = q.value(0).toString();
						QString r_ei = ei ;
						QString contact = q.value(1).toString();
						QString source = q.value(2).toString();
						QString place = q.value(3).toString();
						QString number = q.value(4).toString();
						QString price = q.value(5).toString();
						QString catogory = q.value(6).toString();
						QString tel = q.value(7).toString();
						QString apartment;
						if(flag){
							apartment = apt;
							flag = false;
						}
						else{
							apartment = "";
						}
						records<<goodsname<<r_ei<<place<<source<<number<<price<<catogory<<contact<<tel<<apartment;
						
						//column index
						j = 0;
						//qDebug()<<records;
						while (j<10){
							ui->tableWidget->setItem(i,j,new QTableWidgetItem(records.at(j)));
							j++;
						}
						ui->tableWidget->setCellWidget(i,j,new Button("删除",i,this));
						records.clear();
						i++;
					}
				}
			}
		}
	}
		//QMessageBox::information(this,"success",QString::number(rowCount));		

}


void result::show_refresh(){
	ui->tableWidget->setRowCount(0);
	QSqlQuery q;
	QString sql;

	//apartment list
	QStringList apt_list;

	//ei list
	QStringList ei_list;

	ei_list<<"进货"<<"出货";

	// stores a row of data
	QStringList records;

	ui->tableWidget->setRowCount(20);
	ui->tableWidget->setColumnCount(11);
	QStringList h_header;
	h_header <<"产品名称"<< "进口/出口"<<"交易地点"<<"产地"<<"数量"<<"价格"<<"种类"<<"交易联系人"<<"联系人电话"<<"交易单位"<<"按钮";
	ui->tableWidget->setHorizontalHeaderLabels(h_header);
	ui->tableWidget->verticalHeader()->setVisible(true);

	/*
		select apartment from goodsinfo,contact where goodsinfo.contact = contact.contact
	*/
	sql = "select distinct apartment from goodsinfo,contact where goodsinfo.contact = contact.contact ";
	q.prepare(sql);

	//the sum of row count
	//int rowCount = 0;

	//qDebug()<<"successfully run show_result() function";	

	//execute select apartment
	if(q.exec()){
		int i = 0;
		int j = 0;

		//qDebug()<<"successfully get apartment list";	
		while(q.next()){
			apt_list<<q.value(0).toString();
		}

		//qDebug()<<"apt_list : "<<apt_list;
		for(QString ei:ei_list){

			//qDebug()<<ei;
			for(QString apt : apt_list){

				//qDebug()<<apt<<"is running";
				/*
				select eiinfo.goodsname,eiinfo.contact,source,place,number,price,catogory,tel
				from eiinfo,goodsinfo,contact 
				where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact
				 and apartment="石灰厂" ;
				*/
				sql = "select goodsname,contact,source,place,number,price,catogory,tel"
					" from all_show_info"
				" where ei= :ei and apartment = :apt";
				q.prepare(sql);
				q.bindValue(":apt",apt);
				q.bindValue(":ei",ei);
				bool flag = true;
				if(q.exec()){
					while(q.next()){
			            //qDebug()<<"fetch one record";
			            //QMessageBox::information(this,"success",QString::number(1));
						QString goodsname = q.value(0).toString();
						QString r_ei = ei ;
						QString contact = q.value(1).toString();
						QString source = q.value(2).toString();
						QString place = q.value(3).toString();
						QString number = q.value(4).toString();
						QString price = q.value(5).toString();
						QString catogory = q.value(6).toString();
						QString tel = q.value(7).toString();
						QString apartment;
						if(flag){
							apartment = apt;
							flag = false;
						}
						else{
							apartment = "";
						}
						records<<goodsname<<r_ei<<place<<source<<number<<price<<catogory<<contact<<tel<<apartment;
						
						//column index
						j = 0;
						//qDebug()<<records;
						while (j<10){
							ui->tableWidget->setItem(i,j,new QTableWidgetItem(records.at(j)));
							j++;
						}
						ui->tableWidget->setCellWidget(i,j,new Button("删除",i,this));
						records.clear();
						i++;
					}
				}
			}
		}
	}
		//QMessageBox::information(this,"success",QString::number(rowCount));		

}


void result::doubleClick(int row,int column){
	//QMessageBox::information(this,"success","open double click handler");
	qDebug()<<"double click slots function";
	QSqlQuery q;
	QString goodsname = ui->tableWidget->item(row,0)->text();
	QString ei = ui->tableWidget->item(row,1)->text();
	QString contact = ui->tableWidget->item(row,7)->text();

	QStringList list;
	list<< goodsname<<ei<<contact;

	//pass three parameter and column to modi_dialog() 
	modi_dialog * dialog = new modi_dialog(list,column,this);
	dialog->show();


}

// submit to total database
void result::on_pushButton_clicked(){
	QSqlQuery q;
	QString sql;
	/*
		insert into contact_all
		select * from contact;

		insert into goodsinfo_all
		select * from goodsinfo;

		insert into eiinfo_all
		select * from eiinfo;

		
		delete from goodsinfo;
		delete from eiinfo;
		delete from contact;

		delete from goodsinfo_all;delete from eiinfo_all;delete from contact_all;
	*/
	QStringList sql_list;
	sql_list << "insert into contact_all select * from contact;"<<
		"insert into goodsinfo_all select * from goodsinfo;"<<
		"insert into eiinfo_all select * from eiinfo;"<<
		"delete from goodsinfo;"<<"delete from contact;"<<"delete from eiinfo;"
		;
	int count = 0;
	for(QString sql:sql_list){
		q.prepare(sql);
		if(q.exec()){
			count++;
		}
		else{
			qDebug()<<"this sql fail to insert to whole database"<<sql;
			QMessageBox::warning(this,"fail","提交失败");
		}
	}

	if(count==sql_list.length()){
		QMessageBox::information(this,"success","提交成功");
		emitSignal();
	}
}