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

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &PatientManagement::do_tableView_sort); // 排序点击
}

// 页面显示
void PatientManagement::initView()
{
    IDatabase& instance = IDatabase::GetInstance();

    queryModel = instance.getPatientQueryModel(this);
    filterModel = new QSortFilterProxyModel(this);

    filterModel->setSourceModel(queryModel);
    selModel = new QItemSelectionModel(filterModel, this);

    ui->tableView->setModel(filterModel);
    ui->tableView->setSelectionModel(selModel);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->setSortingEnabled(true);

    ui->tableView->setColumnHidden(0, true); // 隐藏编号

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);

    flag.resize(8, true);
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

    if (queryModel->lastError().isValid())
        QMessageBox::critical(this, "错误", queryModel->lastError().text());

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void PatientManagement::do_btnAdd()
{
    emit add();
}


void PatientManagement::do_btnDelete()
{
    QModelIndex currIndex = selModel->currentIndex();
    QString id = filterModel->data(currIndex.siblingAtColumn(0)).toString();
    QSqlQuery query;
    query.exec("DELETE FROM patient WHERE P_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(this, "错误", query.lastError().text());

    refresh();
}

void PatientManagement::do_btnModify()
{
    emit modify(filterModel, selModel->currentIndex());
}

void PatientManagement::do_tableView_sort(int column)
{
    flag[column] = !flag[column];
    ui->tableView->sortByColumn(column, flag[column] ? Qt::AscendingOrder : Qt::DescendingOrder);
}
