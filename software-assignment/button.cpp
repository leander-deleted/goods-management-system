#include "button.h"

Button::Button(QString text, int row,result * r,QWidget*parent):
	QPushButton(text,parent),
	row(row),
	r(r)
{
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(del_data()));
    //qDebug()<<"connect slots";
}

void Button::del_data(){
	QSqlQuery q;
	QTableWidget *w = qobject_cast<QTableWidget*>(sender()->parent()->parent());

	//qDebug()<<"parent->parent"<<*w;
	QString goodsname = w->item(row,0)->text();
	QString ei = w->item(row,0)->text();
	QString contact = w->item(row,7)->text();
	qDebug()<<"inside del_data() function: "<<"delete row"<< row+1 <<"delete goodsname is :"<<goodsname<<"delete contact is "<<contact;
	//QMessageBox::information(this,"success",goodsname);

	QString sql;
	/*
	delete from goodsinfo where goodsname="轮胎" and contact = "马薇薇";
	*/
	sql = "delete from goodsinfo where goodsname=:goodsname and contact = :contact";
	q.prepare(sql);
	q.bindValue(":goodsname",goodsname);
	q.bindValue(":contact",contact);
	if(q.exec()){
		//QMessageBox::information(this,"success","sucessfully delete from goodsinfo");	
		emit r->emitSignal();
	}
	else {
		QMessageBox::information(this,"fail","fail to delete from goodsinfo");	
	}

}
