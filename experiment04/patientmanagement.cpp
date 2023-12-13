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

    tableModel = instance.getPatientTableModel(this);
    selModel = new QItemSelectionModel(tableModel, this);

    ui->tableView->setModel(tableModel);
    ui->tableView->setSelectionModel(selModel);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    ui->btnFind->setEnabled(!(tableModel->rowCount() == 0));
    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void PatientManagement::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    ui->btnDelete->setEnabled(true);
    ui->btnModify->setEnabled(true);
    ui->btnFind->setEnabled(true);
}

void PatientManagement::do_btnFind()
{
    QString str = ui->lineEdit->text();
    if (str.length() == 0)
        tableModel->setFilter("");
    else
    {
        QString t = " NAME LIKE '%" + str + "%'";
        tableModel->setFilter(t);
//        qDebug() << t;
    }
}

void PatientManagement::do_btnAdd()
{
//    qDebug() << tableModel;
    emit add(tableModel);
}


void PatientManagement::do_btnDelete()
{
    QModelIndex curIndex = selModel->currentIndex();
    tableModel->removeRow(curIndex.row());
    tableModel->select();

    if (tableModel->rowCount() == 0)
    {
        ui->btnDelete->setEnabled(false);
        ui->btnFind->setEnabled(false);
        ui->btnModify->setEnabled(false);
    }
}

void PatientManagement::do_btnModify()
{
    emit modify(tableModel, selModel->currentIndex().row());
}
