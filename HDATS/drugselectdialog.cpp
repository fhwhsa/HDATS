#include "drugselectdialog.h"
#include "ui_drugselectdialog.h"

DrugSelectDialog::DrugSelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrugSelectDialog)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

DrugSelectDialog::~DrugSelectDialog()
{
    if (queryModel != NULL)
        delete queryModel;
    if (selModel != NULL)
        delete selModel;
    delete ui;
}

void DrugSelectDialog::init()
{
    queryModel = IDatabase::GetInstance().getDrugQueryModel(this);
    selModel = new QItemSelectionModel(queryModel, this);

    ui->tableView->setModel(queryModel);
    ui->tableView->setSelectionModel(selModel);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setColumnHidden(0, true); // 隐藏编号

    ui->btnOk->setEnabled(false);
}

void DrugSelectDialog::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnRefreshDrugInfo, SIGNAL(clicked()), this, SLOT(do_btnRefreshDrugInfo()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(do_btnOk()));
    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &DrugSelectDialog::do_currentRowChanged);
}

void DrugSelectDialog::do_btnFind()
{
    QString str = ui->lineEdit->text();

    IDatabase::GetInstance().filterForDrug(queryModel, str, this);

    ui->btnOk->setEnabled(false);
}

void DrugSelectDialog::do_btnRefreshDrugInfo()
{
    IDatabase::GetInstance().filterForDrug(queryModel, "", this);
    ui->lineEdit->setText("");
    ui->btnOk->setEnabled(false);
}

void DrugSelectDialog::do_btnCancel()
{
    this->close();
}

void DrugSelectDialog::do_btnOk()
{
    emit selected(queryModel->data(selModel->currentIndex().siblingAtColumn(1)).toString());
    this->close();
}

void DrugSelectDialog::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    ui->btnOk->setEnabled(true);
}
