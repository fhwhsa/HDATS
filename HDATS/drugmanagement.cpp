#include "drugmanagement.h"
#include "ui_drugmanagement.h"
#include "idatabase.h"

#include <QDebug>

DrugManagement::DrugManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrugManagement)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

DrugManagement::~DrugManagement()
{
    delete ui;
}

void DrugManagement::refresh()
{
    do_btnFind();
}

void DrugManagement::init()
{
    IDatabase& instance = IDatabase::GetInstance();

    queryModel = instance.getDrugQueryModel(this);
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

    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    flag.resize(8, true);
}

void DrugManagement::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(do_btnAdd()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(do_btnDelete()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(do_btnModify()));

    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &DrugManagement::do_currentRowChanged);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &DrugManagement::do_tableView_sort); // 排序点击

}

void DrugManagement::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    ui->btnModify->setEnabled(true);
    ui->btnDelete->setEnabled(true);
}

void DrugManagement::do_btnFind()
{
    QString str = ui->lineEdit->text();

    IDatabase::GetInstance().filterForDrug(queryModel, str, this);

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void DrugManagement::do_btnAdd()
{
    emit add();
}

void DrugManagement::do_btnDelete()
{
    QModelIndex currIndex = selModel->currentIndex();
    QString id = filterModel->data(currIndex.siblingAtColumn(0)).toString();

    IDatabase& instance = IDatabase::GetInstance();
    instance.deleteDrug(id, this);

    refresh();
}

void DrugManagement::do_btnModify()
{
    emit modify(filterModel, selModel->currentIndex());
}

void DrugManagement::do_tableView_sort(int column)
{
    flag[column] = !flag[column];
    ui->tableView->sortByColumn(column, flag[column] ? Qt::AscendingOrder : Qt::DescendingOrder);
}
