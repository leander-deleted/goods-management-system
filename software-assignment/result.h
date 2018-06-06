/*

   QTableWidget *tableWidget;

*/

#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>

#include<QLineEdit>

namespace Ui {
class result;
}

class result : public QWidget
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();
    void emitSignal();

	

signals:
	void QcellDoubleClicked(int row, int column);
	void refresh();

private slots:
	void doubleClick(int row,int column);
	void show_result();

private:
    Ui::result *ui;
    QSqlDatabase db;
};

#endif // RESULT_H
