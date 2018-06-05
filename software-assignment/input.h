/*
	//submit
	QPushButton *pushButton;

	//clear
    QPushButton *pushButton_2;

    //print preview
    QPushButton *pushButton_3;

    QVBoxLayout *verticalLayout;
    QHBoxLayout *catogory;
    
    //catogory label
    QLabel *label;
    QComboBox *comboBox;

    QHBoxLayout *EI;
    //export input label
    QLabel *label_19;
    QComboBox *comboBox_3;

    QHBoxLayout *horizontalLayout_10;
    //name of product
    QLabel *label_18;
    QLineEdit *lineEdit_9;

	//size
    QHBoxLayout *size;
    QLabel *label_17;
    QComboBox *comboBox_2;

	//source
    QLabel *label_16;
    QLineEdit *lineEdit_8;

    //place
    QHBoxLayout *place;
    QLabel *label_15;
    QLineEdit *lineEdit_7;

    //number
    QHBoxLayout *number;
    QLabel *label_14;
    QLineEdit *lineEdit_6;

    //price
    QHBoxLayout *price;
    QLabel *label_13;
    QLineEdit *lineEdit_5;

    // apartment address 
    QHBoxLayout *apartmentAddr;
    QLabel *label_9;
    QLineEdit *lineEdit;

    // contact name
    QHBoxLayout *contactName;
    QLabel *label_10;
    QLineEdit *lineEdit_2;

    //contact tel
    QHBoxLayout *contactTel;
    QLabel *label_11;
    QLineEdit *lineEdit_3;



*/

#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>

namespace Ui {
class input;
}

class input : public QWidget
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = 0);
    ~input();


private slots:
	//submit
	void on_pushButton_clicked();
	//clear 
	void on_pushButton_2_clicked();
	//print preview
	//void on_pushButton_3_clicked();

private:
    Ui::input *ui;
    QSqlDatabase db;

// void setModiUi(QString goodsname="",QString ei="",QString contact="")
};

#endif // INPUT_H
