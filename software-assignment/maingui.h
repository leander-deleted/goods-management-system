#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>

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


private:
	/*
    // title
    QLabel *label;

    // input and modify
    QPushButton *pushButton;

    // print preiew
    QPushButton *pushButton_3;

    // query
    QPushButton *pushButton_4;
	*/

    Ui::mainGui *ui;
};

#endif // MAINGUI_H
