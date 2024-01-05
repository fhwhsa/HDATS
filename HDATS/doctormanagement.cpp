#include "doctormanagement.h"
#include "ui_doctormanagement.h"
#include "idatabase.h"

#include <QDebug>

DoctorManagement::DoctorManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorManagement)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

DoctorManagement::~DoctorManagement()
{
    qDebug() << "delete DoctorManagement";
    delete ui;
}

QString DoctorManagement::baseSql = "SELECT D_ID 编号, D_NAME 姓名, D_SEX 性别, TIMESTAMPDIFF(YEAR, D_BIRTHDATE, CURDATE()) 年龄, "
                                    "D_MOBILEPHOME 电话号码, D_BIRTHDATE 出生日期, PCNO 执业证书号, PLevel 权限等级 FROM doctor";

void DoctorManagement::refresh()
{
    do_btnFind();
}

void DoctorManagement::init()
{
    IDatabase& instance = IDatabase::GetInstance();

    queryModel = instance.getDoctorQueryModel(this);
    filterModel = new QSortFilterProxyModel(this);

    filterModel->setSourceModel(queryModel);
    selModel = new QItemSelectionModel(filterModel, this);

    ui->tableView->setModel(filterModel); // 设置代理
    ui->tableView->setSelectionModel(selModel);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->horizontalHeader()->setSortIndicatorShown(true);

    ui->tableView->setColumnHidden(0, true); // 隐藏编号

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);

    flag.resize(8, true);
}

void DoctorManagement::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(do_btnAdd()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(do_btnDelete()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(do_btnModify()));
    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &DoctorManagement::do_currentRowChanged);
    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &DoctorManagement::do_tableView_sort); // 排序点击
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

    if (queryModel->lastError().isValid())
        QMessageBox::critical(this, "错误", queryModel->lastError().text());

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void DoctorManagement::do_btnAdd()
{
    emit add();
}

void DoctorManagement::do_btnDelete()
{
    QModelIndex currIndex = selModel->currentIndex();
    QString id = filterModel->data(currIndex.siblingAtColumn(0)).toString();

    IDatabase& instance = IDatabase::GetInstance();
    instance.deleteDoctor(id, this);

    refresh();
}

void DoctorManagement::do_btnModify()
{
    emit modify(filterModel, selModel->currentIndex());
}

void DoctorManagement::do_tableView_sort(int column)
{
    flag[column] = !flag[column];
    ui->tableView->sortByColumn(column, flag[column] ? Qt::AscendingOrder : Qt::DescendingOrder);
}
