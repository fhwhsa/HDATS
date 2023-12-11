#include "patientmanagement.h"
#include "ui_patientmanagement.h"

#include <QDebug>

PatientManagement::PatientManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientManagement)
{
    ui->setupUi(this);

    iniSignalSlots();
}

PatientManagement::~PatientManagement()
{
    qDebug() << "delete PatientManagement";
    delete ui;
}

void PatientManagement::iniSignalSlots()
{
    connect(ui->btnAdd, SIGNAL(clicked()), this, SIGNAL(add()));
}
