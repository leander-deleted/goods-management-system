#include "input.h"
#include "ui_input.h"

input::input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
}

//this need to be deleted
input::~input()
{
    delete ui;
}
