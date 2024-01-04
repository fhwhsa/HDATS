#include "welcome.h"
#include "ui_welcome.h"

#include <QDebug>

Welcome::Welcome(QVector<QVariant> info, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);

    currLoginUserID = info[1].toInt();
    currLoginUserName = info[2].toString();
    currLoginUserLevel = info[3].toInt();

    init();
    iniSignalSlots();
}

Welcome::~Welcome()
{
    qDebug() << "delete Welcome";
    delete ui;
}

int Welcome::getCurrLoginUserID()
{
    return currLoginUserID;
}

QString Welcome::getCurrLoginUserName()
{
    return currLoginUserName;
}

int Welcome::getCurrLoginUserLevel()
{
    return currLoginUserLevel;
}

void Welcome::init()
{
    if (currLoginUserLevel == 1); // 开放所有操作
    else { // 不开放药品管理和用户管理
        ui->btnDrugManagement->setEnabled(false);
        ui->btnDepartmentManagement->setEnabled(false);
    }
}

void Welcome::iniSignalSlots()
{
    connect(ui->btnDiagnosticRecords, SIGNAL(clicked()), this, SIGNAL(diagRecords()));
    connect(ui->btnDrugManagement, SIGNAL(clicked()), this, SIGNAL(drugM()));

    connect(ui->btnDoctorManagement, SIGNAL(clicked()), this, SIGNAL(doctorM()));
    connect(ui->btnPatientManagement, SIGNAL(clicked()), this, SIGNAL(patientM()));
}
