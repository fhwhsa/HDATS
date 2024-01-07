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

}

void WorkReportManagement::init()
{

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

}

void WorkReportManagement::do_btnFind()
{

}

void WorkReportManagement::do_btnAdd()
{
    emit add(info);
}

void WorkReportManagement::do_btnDelete()
{

}

void WorkReportManagement::do_btnModify()
{

}

void WorkReportManagement::do_tableView_sort(int column)
{

}
