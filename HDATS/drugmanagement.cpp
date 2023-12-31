#include "drugmanagement.h"
#include "ui_drugmanagement.h"

#include <QDebug>

DrugManagement::DrugManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrugManagement)
{
    ui->setupUi(this);
}

DrugManagement::~DrugManagement()
{
    qDebug() << "delete departmentManagement";
    delete ui;
}
