/*
    // query word 
    QLineEdit *queryWord;

    QRadioButton *precise;
    QRadioButton *vague;

    QLabel *label;

    //result table widget
    QTableWidget *tableWidget;

    //submit to search
    QPushButton *pushButton;

    //precision button group
    QButtonGroup *precisionGroup;

    // search word type
    QComboBox *comboBox;
*/

#ifndef QUERY_H
#define QUERY_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<String>

namespace Ui {
class query;
}

class query : public QWidget
{
    Q_OBJECT

public:
    explicit query(QWidget *parent = 0);
    ~query();

private slots:
	void on_pushButton_clicked();

private:
    Ui::query *ui;
    QSqlDatabase db;
};

#endif // QUERY_H
