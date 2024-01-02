#include "doctormanagement.h"
#include "ui_doctormanagement.h"
#include "idatabase.h"

#include <QDebug>

DoctorManagement::DoctorManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorManagement)
{
    ui->setupUi(this);

    initView();
    iniSignalSlots();
}

DoctorManagement::~DoctorManagement()
{
    qDebug() << "delete DoctorManagement";
    delete ui;
}

void DoctorManagement::refresh()
{
    do_btnFind();
}

QString DoctorManagement::baseSql = "SELECT D_ID 编号, D_NAME 姓名, D_SEX 性别, TIMESTAMPDIFF(YEAR, D_BIRTHDATE, CURDATE()) 年龄, "
                                    "D_MOBILEPHOME 电话号码, D_BIRTHDATE 出生日期, PCNO 执业证书号, PLevel 权限等级 FROM doctor";

void DoctorManagement::initView()
{
    IDatabase& instance = IDatabase::GetInstance();

    queryModel = instance.getDoctorQueryModel(this);
    selModel = new QItemSelectionModel(queryModel, this);

    ui->tableView->setModel(queryModel);
    ui->tableView->setSelectionModel(selModel);

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void DoctorManagement::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(do_btnAdd()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(do_btnDelete()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(do_btnModify()));
    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &DoctorManagement::do_currentRowChanged);
}

void DoctorManagement::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    ui->btnDelete->setEnabled(true);
    ui->btnModify->setEnabled(true);
}

void DoctorManagement::do_btnFind()
{
    QString str = ui->lineEdit->text();
    if (str.length() == 0)
        queryModel->setQuery(baseSql);
    else
    {
        QString t = " D_NAME LIKE '%" + str + "%'";
        queryModel->setQuery(baseSql + " WHERE " + t);
    }

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void DoctorManagement::do_btnAdd()
{
    emit add();
}

void DoctorManagement::do_btnDelete()
{
    QModelIndex curIndex = selModel->currentIndex();
    QString id = queryModel->record(curIndex.row()).value("编号").toString();
    QSqlQuery query;
    query.exec("DELETE FROM doctor WHERE D_ID = " + id);
    refresh();
}

void DoctorManagement::do_btnModify()
{
    emit modify(queryModel, selModel->currentIndex().row());
}
