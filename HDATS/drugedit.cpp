#include "drugedit.h"
#include "ui_drugedit.h"

#include "idatabase.h"

#include <QDebug>

DrugEdit::DrugEdit(QString op, QWidget *parent) :
    QWidget(parent),
    operation(op),
    ui(new Ui::DrugEdit)
{
    ui->setupUi(this);

    iniSignalSlots();
}

DrugEdit::DrugEdit(QSortFilterProxyModel *sfpm, QModelIndex i, QString op, QWidget *parent) :
    QWidget(parent),
    sfpm(sfpm),
    index(i),
    operation(op),
    ui(new Ui::DrugEdit)
{
    ui->setupUi(this);

    initData();
    iniSignalSlots();
}

DrugEdit::~DrugEdit()
{
    qDebug() << "delete drugEdit";
    delete ui;
}

QString DrugEdit::insertPrepare = "INSERT INTO drug (DRUG_NAME, INVENTORY, DRUG_INTRODUCTION_TIME) VALUES (?, ?, ?)";

QString DrugEdit::updatePrepare = "UPDATE drug SET DRUG_NAME = ?, INVENTORY = ? WHERE DRUG_ID = ?";

void DrugEdit::initData()
{
    ui->drugName->setText(sfpm->data(index.siblingAtColumn(1)).toString());
    ui->inventory->setValue(sfpm->data(index.siblingAtColumn(2)).toInt());
}

void DrugEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

void DrugEdit::do_btnSave()
{
    QString name = ui->drugName->text();
    int inventory = ui->inventory->value();

    if (name.length() == 0)
    {
        QMessageBox::critical(this, "错误", "信息填写不完整");
        return;
    }
    if (((operation == "修改" && sfpm->data(index.siblingAtColumn(1)).toString() != name) || operation == "添加")
        && IDatabase::GetInstance().findDrug(name))
    {
        QMessageBox::critical(this, "错误", "药品重复");
        return;
    }

    QSqlQuery query;
    if (operation == "添加")
        query.prepare(insertPrepare);
    else
        query.prepare(updatePrepare);

    query.bindValue(0, name);
    query.bindValue(1, inventory);
    if (operation == "添加")
        query.bindValue(2, QDate::currentDate());
    else
        query.bindValue(2, sfpm->data(index.siblingAtColumn(0)).toInt());

    if (!query.exec())
    {
        QMessageBox::critical(this, "错误", query.lastError().text() + "\n" + query.lastQuery());
        return;
    }

    emit clickBtnSave();
}

void DrugEdit::do_btnCancel()
{
    emit clickBtnCancel();
}
