#include "button.h"

Button::Button(QString text, result * r,QWidget*parent):
	QPushButton(text,parent),
	r(r)
{
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(del_data()));
    //qDebug()<<"connect slots";
}

void Button::del_data(){
	QSqlQuery q;
	//QMessageBox::information(this,"success","sucessfully run slot handler");
	QWidget * w = qobject_cast<QWidget*>(sender()->parent());
	QTableWidget * table = qobject_cast<QTableWidget*>(w->parent());
	int row = table->indexAt(w->pos()).row();

	QString goodsname = table->item(row,0)->text();
	QString ei = table->item(row,0)->text();
	QString contact = table->item(row,7)->text();

	//QMessageBox::information(this,"success",goodsname);

	QString sql;
	/*
	delete from goodsinfo where goodsname="工数" and contact = "老王";
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
