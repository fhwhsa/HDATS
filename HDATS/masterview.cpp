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
    ui->currWidgetTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());
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

void MasterView::goToWelcomeView()
{
    welcome = new Welcome();
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
}

void MasterView::goToPatientMView()
{
    patientManagement = new PatientManagement();
    pushToStack(patientManagement);

    connect(patientManagement, &PatientManagement::add, this, &MasterView::goToPatientEditViewForAdd); // 添加
    connect(patientManagement, &PatientManagement::modify, this, &MasterView::goToPatientEditViewForModify); // 修改
}

void MasterView::goToPatientEditViewForAdd(QSqlTableModel *tm)
{
    patientEdit = new PatientEdit(tm);
    patientEdit->setWindowTitle("添加患者信息");
    pushToStack(patientEdit);

    connect(patientEdit, &PatientEdit::clickBtnSave, this, &MasterView::back); // 返回上一页
    connect(patientEdit, &PatientEdit::clickBtnCancel, this, &MasterView::back);
}

void MasterView::goToPatientEditViewForModify(QSqlTableModel *tm, int index)
{
    patientEdit = new PatientEdit(tm, index);
//    patientEdit->setWindowTitle("编辑患者信息"); 默认
    pushToStack(patientEdit);

    connect(patientEdit, &PatientEdit::clickBtnSave, this, &MasterView::back);
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
