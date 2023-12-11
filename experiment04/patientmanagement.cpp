#include "patientmanagement.h"
#include "ui_patientmanagement.h"

PatientManagement::PatientManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientManagement)
{
    ui->setupUi(this);
}

PatientManagement::~PatientManagement()
{
    delete ui;
}
