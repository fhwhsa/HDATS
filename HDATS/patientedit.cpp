#include "patientedit.h"
#include "ui_patientedit.h"

#include <QDebug>

PatientEdit::PatientEdit(QSqlTableModel *tm, int f, QWidget *parent) :
    QWidget(parent),
    tableModel(tm),
    modifyIndex(f),
    ui(new Ui::PatientEdit)
{
    ui->setupUi(this);
    iniSignalSlots();
    if (f != -1)
        initData();
}

PatientEdit::~PatientEdit()
{
    qDebug() << "delete PatientEdit";
    delete ui;
}

void PatientEdit::initData()
{
    QSqlRecord rec = tableModel->record(modifyIndex);
    ui->name->setText(rec.value("P_NAME").toString());
    ui->gender->setCurrentIndex((rec.value("P_SEX").toString() == "男") ? 0 : 1);
    ui->height->setValue(rec.value("HEIGHT").toDouble());
    ui->weight->setValue(rec.value("WEIGHT").toDouble());
    ui->phoneNum->setText(rec.value("P_MOBILEPHOME").toString());
}

void PatientEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

void PatientEdit::do_btnSave()
{
    qDebug() << tableModel;
    QSqlRecord rec = modifyIndex != -1 ? tableModel->record(modifyIndex) : tableModel->record();
    QDate date = QDate::currentDate();

    rec.setValue("P_NAME", ui->name->text());
    rec.setValue("P_MOBILEPHOME", ui->phoneNum->text());
    rec.setValue("P_SEX", ui->gender->currentText());
    rec.setValue("P_AGE", date.year() - ui->dateOfBirth->date().year());
    rec.setValue("HEIGHT", ui->height->text());
    rec.setValue("WEIGHT", ui->weight->text());


    if (modifyIndex == -1) // 添加操作
        tableModel->insertRecord(tableModel->rowCount(), rec);

    else // 修改操作
    {
        tableModel->setRecord(modifyIndex, rec);
//        qDebug() << tableModel->lastError().text();
    }

    tableModel->setFilter("");
    emit clickBtnSave();
}

void PatientEdit::do_btnCancel()
{
    emit clickBtnCancel();
}
