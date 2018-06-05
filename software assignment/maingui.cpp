#include "maingui.h"
#include "ui_maingui.h"

mainGui::mainGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainGui)
{
    ui->setupUi(this);
}

mainGui::~mainGui()
{
    delete ui;
}
