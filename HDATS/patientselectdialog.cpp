#include "patientselectdialog.h"
#include "ui_patientselectdialog.h"

PatientSelectDialog::PatientSelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientSelectDialog)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

PatientSelectDialog::~PatientSelectDialog()
{
    if (queryModel != NULL)
        delete queryModel;
    if (selModel != NULL)
        delete selModel;
    delete ui;
}

void PatientSelectDialog::init()
{
    queryModel = IDatabase::GetInstance().getPatientQueryModel(this);
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

void PatientSelectDialog::iniSignalSlots()
{
    connect(ui->btnFind, SIGNAL(clicked()), this, SLOT(do_btnFind()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(do_btnOk()));
    connect(selModel, &QItemSelectionModel::currentRowChanged, this, &PatientSelectDialog::do_currentRowChanged);
}

void PatientSelectDialog::do_btnFind()
{
    QString str = ui->lineEdit->text();

    IDatabase::GetInstance().filterForPatient(queryModel, str, this);

    ui->btnOk->setEnabled(false);
}

void PatientSelectDialog::do_btnCancel()
{
    this->close();
}

void PatientSelectDialog::do_btnOk()
{
    emit selected(queryModel->data(selModel->currentIndex().siblingAtColumn(1)).toString());
    this->close();
}

void PatientSelectDialog::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug() << current.row();
    ui->btnOk->setEnabled(true);
}
