/*
    QLabel *label;

    //input
    QPushButton *pushButton;

    //print preview
    QPushButton *pushButton_3;

    //query
    QPushButton *pushButton_4;

    //dump backup
    QPushButton *pushButton_5;

*/

#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>
#include<cstdlib>
#include <fstream>
#include <iostream>
#include <QMessageBox>

namespace Ui {
class mainGui;
}

class mainGui : public QWidget
{
    Q_OBJECT

public:
    explicit mainGui(QWidget *parent = 0);
    ~mainGui();


private slots:
	void on_pushButton_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::mainGui *ui;
};

#endif // MAINGUI_H
