#include "departmentmanagement.h"
#include "ui_departmentmanagement.h"

#include <QDebug>

DepartmentManagement::DepartmentManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentManagement)
{
    ui->setupUi(this);
}

DepartmentManagement::~DepartmentManagement()
{
    qDebug() << "delete DepartmentManagement";
    delete ui;
}
