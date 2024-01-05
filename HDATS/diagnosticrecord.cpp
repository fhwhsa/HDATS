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
    delete ui;
}

QString DiagnosticRecord::drBaseSql = "SELECT DR_ID 编号, D_NAME 医生姓名, P_NAME 患者姓名, CONTEXT 诊断内容,DATEOFVISIT 创建时间 "
                                      "FROM diagnostic_records";

QString DiagnosticRecord::mrBaseSql = "SELECT MRDR_ID, MRDRUG_ID, d.DRUG_NAME 药品名字, dose 剂量 "
                                      "FROM medication_record mr INNER JOIN drug d ON mr.MRDRUG_ID = d.DRUG_ID";

void DiagnosticRecord::refresh()
{
    do_btnFind();
}

void DiagnosticRecord::init()
{
    IDatabase& instance = IDatabase::GetInstance();

    drQueryModel = instance.getDiagnosticRecord(this);
//    mrQueryModel = new QSqlQueryModel(); // 不直接new是因为方便隐藏前两列
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

    ui->mrTableView->setColumnHidden(0, true);
    ui->mrTableView->setColumnHidden(1, true);

    mrQueryModel->setQuery(mrBaseSql + " WHERE MRDR_ID = 0"); // 让数据为空
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
    QString t = " MRDR_ID LIKE '%" + filterModel->data(selModel->currentIndex().siblingAtColumn(0)).toString() + "%'";
    mrQueryModel->setQuery(mrBaseSql + " WHERE " + t);

    if (mrQueryModel->lastError().isValid())
        QMessageBox::critical(this, "错误", mrQueryModel->lastError().text());
}

void DiagnosticRecord::do_btnFind()
{
    QString str = ui->lineEdit->text();
    QString type = ui->findType->currentText();

    if (str.length() == 0)
        drQueryModel->setQuery(drBaseSql);
    else
    {
        QString t = (type == "医生" ? tr(" D_NAME ") : tr(" P_NAME ")) + " LIKE '%" + str + "%'";
        drQueryModel->setQuery(drBaseSql + " WHERE " + t);
    }

    mrQueryModel->setQuery(mrBaseSql + " WHERE MRDR_ID = 0");

    if (drQueryModel->lastError().isValid() || mrQueryModel->lastError().isValid())
        QMessageBox::critical(this, "错误", "就诊记录表错误：" + drQueryModel->lastError().text() +
                                            "\n开具药品表错误：" + mrQueryModel->lastError().text());

    ui->btnDelete->setEnabled(false);
    ui->btnModify->setEnabled(false);
}

void DiagnosticRecord::do_btnAdd()
{
    emit add();
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
    QSqlQuery query;
    query.exec("DELETE FROM diagnostic_records WHERE DR_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(this, "错误", query.lastError().text());

    refresh();
}

void DiagnosticRecord::do_btnModify()
{
    if (info->getUserLevel() != 1)
    {
        QMessageBox::warning(this, "警告", "权限不足");
        return;
    }
}

void DiagnosticRecord::do_tableView_sort(int column)
{
    flag[column] = !flag[column];
    ui->drTableView->sortByColumn(column, flag[column] ? Qt::AscendingOrder : Qt::DescendingOrder);
}
