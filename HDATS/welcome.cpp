#include "welcome.h"
#include "ui_welcome.h"

#include <QDebug>

Welcome::Welcome(int qLevel, QWidget *parent) :
    level(qLevel),
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    init();
    iniSignalSlots();
}

Welcome::~Welcome()
{
    qDebug() << "delete Welcome";
    delete ui;
}

void Welcome::init()
{
    if (level == 1); // 开放所有操作
    else { // 仅开放患者管理和就诊记录管理
        ui->btnDrugManagement->setEnabled(false);
        ui->btnDepartmentManagement->setEnabled(false);
        ui->btnDoctorManagement->setEnabled(false);
    }
}

void Welcome::iniSignalSlots()
{
    connect(ui->btnDiagnosticRecords, SIGNAL(clicked()), this, SIGNAL(diagRecords()));
    connect(ui->btnDrugManagement, SIGNAL(clicked()), this, SIGNAL(drugM()));
    connect(ui->btnDepartmentManagement, SIGNAL(clicked()), this, SIGNAL(departmentM()));
    connect(ui->btnDoctorManagement, SIGNAL(clicked()), this, SIGNAL(doctorM()));
    connect(ui->btnPatientManagement, SIGNAL(clicked()), this, SIGNAL(patientM()));
}
