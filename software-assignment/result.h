/*

   QTableWidget *tableWidget;

*/

#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>

namespace Ui {
class result;
}

class result : public QWidget
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();

private:
	void show_result();
	
signals:
	void QcellDoubleClicked(int row, int column);

private slots:
	void doubleClick(int row,int column);

private:
    Ui::result *ui;
    QSqlDatabase db;
};

#endif // RESULT_H
