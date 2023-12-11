#include "doctormanagement.h"
#include "ui_doctormanagement.h"

DoctorManagement::DoctorManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorManagement)
{
    ui->setupUi(this);
}

DoctorManagement::~DoctorManagement()
{
    delete ui;
}
