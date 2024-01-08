#include "workreportmanagement.h"
#include "ui_workreportmanagement.h"

WorkReportManagement::WorkReportManagement(CurrLoginUserInfo *info, QWidget *parent) :
    QWidget(parent),
    info(info),
    ui(new Ui::WorkReportManagement)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

WorkReportManagement::~WorkReportManagement()
{
    delete ui;
}

void WorkReportManagement::refresh()
{
    do_btnFind();
}

void WorkReportManagement::init()
{
    IDatabase& instance = IDatabase::GetInstance();

    queryModel = instance.getWorkReportQueryModel(this);
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
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);

    ui->diagnosisSituation->setReadOnly(true);
    ui->treatmentEffect->setReadOnly(true);

    flag.resize(8, true);
}

void WorkReportManagement::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(do_btnAdd()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(do_btnDelete()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(do_btnModify()));
    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &WorkReportManagement::do_currentRowChanged);
    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &WorkReportManagement::do_tableView_sort); // 排序点击
}

void WorkReportManagement::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    ui->btnDelete->setEnabled(true);
    ui->btnModify->setEnabled(true);

    ui->diagnosisSituation->setPlainText(filterModel->data(current.siblingAtColumn(4)).toString());
    ui->treatmentEffect->setPlainText(filterModel->data(current.siblingAtColumn(5)).toString());
}

void WorkReportManagement::do_btnFind()
{
    QString str = ui->lineEdit->text();

    IDatabase::GetInstance().filterForWorkReports(queryModel, str, this);

    ui->diagnosisSituation->setPlainText("");
    ui->treatmentEffect->setPlainText("");

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void WorkReportManagement::do_btnAdd()
{
    emit add(info);
}

void WorkReportManagement::do_btnDelete()
{
    QString id = filterModel->data(selModel->currentIndex().siblingAtColumn(0)).toString();
    IDatabase::GetInstance().deleteWorkReport(id, this);

    refresh();
}

void WorkReportManagement::do_btnModify()
{
    emit modify(info, filterModel, selModel->currentIndex());
}

void WorkReportManagement::do_tableView_sort(int column)
{
    flag[column] = !flag[column];
    ui->tableView->sortByColumn(column, flag[column] ? Qt::AscendingOrder : Qt::DescendingOrder);
}
