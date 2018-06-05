#include "query.h"
#include "ui_query.h"

query::query(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::query)
{
    ui->setupUi(this);
}

query::~query()
{
    delete ui;
}
