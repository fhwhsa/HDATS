#include "diagnosticrecord.h"
#include "ui_diagnosticrecord.h"
#include "idatabase.h"

#include <QDebug>

DiagnosticRecord::DiagnosticRecord(CurrLoginUserInfo *info, QWidget *parent) :
    QWidget(parent),
    info(info),
    ui(new Ui::DiagnosticRecord)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

DiagnosticRecord::~DiagnosticRecord()
{
    qDebug() << "delete diagnosticRecord";
    if (drQueryModel != NULL)
        delete drQueryModel;
    if (mrQueryModel != NULL)
        delete mrQueryModel;
    if (selModel != NULL)
        delete selModel;
    if (filterModel != NULL)
        delete filterModel;
    delete ui;
}

void DiagnosticRecord::refresh()
{
    do_btnFind();
}

void DiagnosticRecord::init()
{
    IDatabase& instance = IDatabase::GetInstance();

    drQueryModel = instance.getDiagnosticRecord(this);
    mrQueryModel = instance.getMedicationRecords(this);
    filterModel = new QSortFilterProxyModel();

    filterModel->setSourceModel(drQueryModel);
    selModel = new QItemSelectionModel(filterModel, this);


    // 就诊记录表设置
    ui->drTableView->setModel(filterModel);
    ui->drTableView->setSelectionModel(selModel);

    ui->drTableView->verticalHeader()->hide();
    ui->drTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->drTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->drTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->drTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->drTableView->horizontalHeader()->setSortIndicatorShown(true);
    ui->drTableView->setColumnHidden(0, true);

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);

    flag.resize(8, true);



    // 药品开具记录表设置
    ui->mrTableView->setModel(mrQueryModel);

    ui->mrTableView->verticalHeader()->hide();
    ui->mrTableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->mrTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->mrTableView->setColumnHidden(0, true);

    IDatabase::GetInstance().filterForMedicationRecords(mrQueryModel, "0", this);
}

void DiagnosticRecord::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(do_btnAdd()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(do_btnDelete()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(do_btnModify()));
    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &DiagnosticRecord::do_currentRowChanged);
    connect(ui->drTableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &DiagnosticRecord::do_tableView_sort);
}

void DiagnosticRecord::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    ui->btnDelete->setEnabled(true);
    ui->btnModify->setEnabled(true);

    // 显示药品信息
    IDatabase::GetInstance().filterForMedicationRecords(mrQueryModel,
                            filterModel->data(selModel->currentIndex().siblingAtColumn(0)).toString(), this);
}

void DiagnosticRecord::do_btnFind()
{
    QString str = ui->lineEdit->text();
    QString type = ui->findType->currentText();

    IDatabase& instance = IDatabase::GetInstance();
    instance.filterForDiagnosticRecord(drQueryModel, str, type, this);
    instance.filterForMedicationRecords(mrQueryModel, tr("0"), this);

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void DiagnosticRecord::do_btnAdd()
{
    emit add(info);
}

void DiagnosticRecord::do_btnDelete()
{
    if (info->getUserLevel() != 1)
    {
        QMessageBox::warning(this, "警告", "权限不足");
        return;
    }
    QModelIndex currIndex = selModel->currentIndex();
    QString id = filterModel->data(currIndex.siblingAtColumn(0)).toString();

    IDatabase::GetInstance().deleteDiagnosticRecord(id, this);

    refresh();
}

void DiagnosticRecord::do_btnModify()
{
    if (info->getUserLevel() != 1)
    {
        QMessageBox::warning(this, "警告", "权限不足");
        return;
    }
    emit modify(filterModel, info, selModel->currentIndex());
}

void DiagnosticRecord::do_tableView_sort(int column)
{
    flag[column] = !flag[column];
    ui->drTableView->sortByColumn(column, flag[column] ? Qt::AscendingOrder : Qt::DescendingOrder);
}
