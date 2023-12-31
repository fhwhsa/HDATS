#include "doctormanagement.h"
#include "ui_doctormanagement.h"

#include <QDebug>

DoctorManagement::DoctorManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorManagement)
{
    ui->setupUi(this);
}

DoctorManagement::~DoctorManagement()
{
    qDebug() << "delete DoctorManagement";
    delete ui;
}
