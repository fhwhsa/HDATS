#include "masterview.h"
#include "ui_masterview.h"
#include "idatabase.h"

#include <QDebug>

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);
    iniSignalSlots();
    ui->btnReturn->setEnabled(false);
    ui->btnLoginout->setEnabled(false);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    goToLoginView();

}

MasterView::~MasterView()
{
    delete ui;
}

// 初始化信号连接
void MasterView::iniSignalSlots()
{
    connect(ui->btnReturn, SIGNAL(clicked()), this, SLOT(back()));
    connect(ui->btnLoginout, SIGNAL(clicked()), this, SLOT(loginout()));
    connect(ui->stackedWidget, SIGNAL(currentChanged(int)), this, SLOT(pageChange(int)));
}

// 添加窗口
void MasterView::pushToStack(QWidget *w)
{
    ui->stackedWidget->addWidget(w);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
    ui->currWidgetTitle->setText(w->windowTitle());
}

// 回到上一个窗口
void MasterView::back()
{
    int cnt = ui->stackedWidget->count();
    QWidget *w = ui->stackedWidget->currentWidget();
    ui->stackedWidget->setCurrentIndex(cnt - 2);

    QString currWin = ui->stackedWidget->currentWidget()->windowTitle();
    ui->currWidgetTitle->setText(currWin);

    if (currWin == "患者管理")
        patientManagement->refresh();
    else if (currWin == "医生管理")
        doctorManagement->refresh();

    delete w;
}

void MasterView::loginout()
{
    int cnt = ui->stackedWidget->count();
    for (int i = 1; i < cnt; i++)
        back();
}

void MasterView::goToLoginView()
{
    login = new Login();
    pushToStack(login);

    connect(login, &Login::loginSuccess, this, &MasterView::goToWelcomeView);
}

void MasterView::goToWelcomeView(int pLevel)
{
    welcome = new Welcome(pLevel);
    pushToStack(welcome);

    connect(welcome, &Welcome::diagRecords, this, &MasterView::goToDiagnosticRecords);
    connect(welcome, &Welcome::drugM, this, &MasterView::goToDrugMView);
    connect(welcome, &Welcome::departmentM, this, &MasterView::goToDepartmentM);
    connect(welcome, &Welcome::doctorM, this, &MasterView::goToDoctorMView);
    connect(welcome, &Welcome::patientM, this, &MasterView::goToPatientMView);


}

void MasterView::goToDiagnosticRecords()
{
    diagnosticRecords = new DiagnosticRecords;
    pushToStack(diagnosticRecords);
}

void MasterView::goToDrugMView()
{
    drugManagement = new DrugManagement();
    pushToStack(drugManagement);
}

void MasterView::goToDepartmentM()
{

    departmentManagement = new DepartmentManagement();
    pushToStack(departmentManagement);
}

void MasterView::goToDoctorMView()
{
    doctorManagement = new DoctorManagement();
    pushToStack(doctorManagement);

    connect(doctorManagement, &DoctorManagement::add, this, &MasterView::goToDoctorEditViewForAdd);
    connect(doctorManagement, &DoctorManagement::modify, this, &MasterView::goToDoctorEditViewForModify);
}

void MasterView::goToDoctorEditViewForAdd()
{
    doctorEdit = new DoctorEdit("添加");
    doctorEdit->setWindowTitle("添加医生信息");
    pushToStack(doctorEdit);

    connect(doctorEdit, &DoctorEdit::clickBtnSave, this, &MasterView::back);
    connect(doctorEdit, &DoctorEdit::clickBtnCancel, this, &MasterView::back);
}

void MasterView::goToDoctorEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index)
{
    doctorEdit = new DoctorEdit(sfpm, index, "修改");
//    doctorEdit->setWindowTitle("编辑医生信息"); 默认
    pushToStack(doctorEdit);

    connect(doctorEdit, &DoctorEdit::clickBtnSave, this, &MasterView::back);
    connect(doctorEdit, &DoctorEdit::clickBtnCancel, this, &MasterView::back);
}

void MasterView::goToPatientMView()
{
    patientManagement = new PatientManagement();
    pushToStack(patientManagement);

    connect(patientManagement, &PatientManagement::add, this, &MasterView::goToPatientEditViewForAdd); // 添加
    connect(patientManagement, &PatientManagement::modify, this, &MasterView::goToPatientEditViewForModify); // 修改
}

void MasterView::goToPatientEditViewForAdd()
{
    patientEdit = new PatientEdit("添加");
    patientEdit->setWindowTitle("添加患者信息");
    pushToStack(patientEdit);

    connect(patientEdit, &PatientEdit::clickBtnSave, this, &MasterView::back); // 返回上一页
    connect(patientEdit, &PatientEdit::clickBtnCancel, this, &MasterView::back);
}

void MasterView::goToPatientEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index)
{
    patientEdit = new PatientEdit(sfpm, index, "修改");
//    patientEdit->setWindowTitle("编辑患者信息"); 默认
    pushToStack(patientEdit);

    connect(patientEdit, &PatientEdit::clickBtnSave, this, &MasterView::back); // 返回上一页
    connect(patientEdit, &PatientEdit::clickBtnCancel, this, &MasterView::back);
}


void MasterView::pageChange(int index)
{
    qDebug() << index;
    if (ui->stackedWidget->currentWidget()->windowTitle() == "欢迎")
    {
        ui->btnLoginout->setDisabled(false);
        ui->btnReturn->setDisabled(true);
    }
    else if (index == 0)
        ui->btnReturn->setDisabled(true);
    else
    {
        ui->btnLoginout->setDisabled(true);
        ui->btnReturn->setDisabled(false);
    }
}
