#include "departmentmanagement.h"
#include "ui_departmentmanagement.h"

DepartmentManagement::DepartmentManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentManagement)
{
    ui->setupUi(this);
}

DepartmentManagement::~DepartmentManagement()
{
    delete ui;
}
