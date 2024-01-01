#include "patientmanagement.h"
#include "ui_patientmanagement.h"
#include "idatabase.h"

#include <QDebug>

PatientManagement::PatientManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientManagement)
{
    ui->setupUi(this);

    qDebug() << "hello";
    initView();
    iniSignalSlots();
}

PatientManagement::~PatientManagement()
{
    qDebug() << "delete PatientManagement";
    delete ui;
}

void PatientManagement::refresh()
{
    do_btnFind();
}

QString PatientManagement::baseSql = "SELECT P_ID 编号, P_NAME 姓名, P_SEX 性别, TIMESTAMPDIFF(YEAR, P_BIRTHDATE, CURDATE()) 年龄, "
                                     "P_MOBILEPHOME 电话号码, HEIGHT 身高, WEIGHT 体重, P_BIRTHDATE 出生日期 FROM patient";

void PatientManagement::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(do_btnAdd()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(do_btnDelete()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(do_btnModify()));
    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &PatientManagement::do_currentRowChanged);
}

// 页面显示
void PatientManagement::initView()
{
    IDatabase& instance = IDatabase::GetInstance();

    queryModel = instance.getPatientQueryModel(this);
    selModel = new QItemSelectionModel(queryModel, this);

    ui->tableView->setModel(queryModel);
    ui->tableView->setSelectionModel(selModel);

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void PatientManagement::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    ui->btnDelete->setEnabled(true);
    ui->btnModify->setEnabled(true);
}

void PatientManagement::do_btnFind()
{
    QString str = ui->lineEdit->text();
    if (str.length() == 0)
        queryModel->setQuery(baseSql);
    else
    {
        QString t = " P_NAME LIKE '%" + str + "%'";
        queryModel->setQuery(baseSql + " WHERE " + t);
    }

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void PatientManagement::do_btnAdd()
{
    emit add(tableModel);
}


void PatientManagement::do_btnDelete()
{
    QModelIndex curIndex = selModel->currentIndex();
    QString id = queryModel->record(curIndex.row()).value("编号").toString();
    QSqlQuery query;
    query.exec("DELETE FROM patient WHERE P_ID = " + id);
    refresh();
}

void PatientManagement::do_btnModify()
{
    emit modify(queryModel, selModel->currentIndex().row());
}
