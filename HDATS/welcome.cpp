#include "welcome.h"
#include "ui_welcome.h"

#include <QDebug>

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    iniSignalSlots();
}

Welcome::~Welcome()
{
    qDebug() << "delete Welcome";
    delete ui;
}

void Welcome::iniSignalSlots()
{
    connect(ui->btnDiagnosticRecords, SIGNAL(clicked()), this, SIGNAL(diagRecords()));
    connect(ui->btnDrugManagement, SIGNAL(clicked()), this, SIGNAL(drugM()));
    connect(ui->btnDepartmentManagement, SIGNAL(clicked()), this, SIGNAL(departmentM()));
    connect(ui->btnDoctorManagement, SIGNAL(clicked()), this, SIGNAL(doctorM()));
    connect(ui->btnPatientManagement, SIGNAL(clicked()), this, SIGNAL(patientM()));
}
