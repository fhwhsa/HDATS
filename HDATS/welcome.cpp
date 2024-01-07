#include "welcome.h"
#include "ui_welcome.h"

#include <QDebug>

Welcome::Welcome(CurrLoginUserInfo *info, QWidget *parent) :
    QWidget(parent),
    info(info),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);


    init();
    iniSignalSlots();
}

Welcome::~Welcome()
{
    qDebug() << "delete Welcome";
    if (info != NULL)
        delete info;
    delete ui;
}

void Welcome::init()
{
    if (info->getUserLevel() == 1); // 开放所有操作
    else { // 不开放药品管理和用户管理
        ui->btnDrugManagement->setEnabled(false);
        ui->btnDoctorManagement->setEnabled(false);
    }
}

void Welcome::iniSignalSlots()
{
    connect(ui->btnDiagnosticRecords, &QPushButton::clicked, [this]() {
        emit diagRecords(info);
    });
    connect(ui->btnWorkReportManagement, &QPushButton::clicked, [this]() {
        emit workReportM(info);
    });
    connect(ui->btnDrugManagement, SIGNAL(clicked()), this, SIGNAL(drugM()));
    connect(ui->btnDoctorManagement, SIGNAL(clicked()), this, SIGNAL(doctorM()));
    connect(ui->btnPatientManagement, SIGNAL(clicked()), this, SIGNAL(patientM()));
}
