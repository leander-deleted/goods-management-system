/*
    QLabel *label;

    //id
    QLineEdit *lineEdit;

    //password
    QLineEdit *lineEdit_2;
    QLabel *label_2;

    //submit
    QPushButton *pushButton;

    //clear
    QPushButton *pushButton_2;
*/

#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QMessageBox>

#include<QDebug>
#include<iostream>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
	void test_func();

private:
    Ui::login *ui;
    QSqlDatabase db ;

};

#endif // LOGIN_H
