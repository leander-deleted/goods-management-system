#include "result.h"
#include "ui_result.h"
#include "common.h"
#include "modi_dialog.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    init_db(db);
    show_result();
    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doubleClick(int,int)));
 	//QMessageBox::information(this,"success","open result cpp");
   
}

result::~result()
{
    delete ui;
}

void result::show_result(){
	QSqlQuery q;
	QString sql;
	sql = "select eiinfo.goodsname,ei,eiinfo.contact,source,place,number,price,catogory,tel,apartment"
		" from eiinfo,goodsinfo,contact "
		" where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact";
	q.prepare(sql);
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


}


void result::doubleClick(int row,int column){
	//QMessageBox::information(this,"success","open double click handler");

	QSqlQuery q;
	QString goodsname = ui->tableWidget->item(row,0)->text();
	QString ei = ui->tableWidget->item(row,1)->text();
	QString contact = ui->tableWidget->item(row,7)->text();

	//pass three parameter and column to modi_dialog() 



}