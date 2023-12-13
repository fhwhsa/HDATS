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
    ui->id->setText(rec.value("ID").toString());
    ui->idCard->setText(rec.value("ID_CARD").toString());
    ui->name->setText(rec.value("NAME").toString());
    ui->gender->setCurrentIndex((rec.value("SEX").toString() == "男") ? 0 : 1);
    ui->height->setValue(rec.value("HEIGHT").toDouble());
    ui->weight->setValue(rec.value("WEIGHT").toDouble());
    ui->phoneNum->setText(rec.value("MOBILEPHOME").toString());
}

void PatientEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

void PatientEdit::do_btnSave()
{
    qDebug() << tableModel;
    QSqlRecord rec = tableModel->record();
    QDate date = QDate::currentDate();

    rec.setValue("ID", ui->id->text());
    rec.setValue("ID_CARD", ui->idCard->text());
    rec.setValue("NAME", ui->name->text());
    rec.setValue("SEX", ui->gender->currentText());
    rec.setValue("DOB", "");
    rec.setValue("HEIGHT", ui->height->text());
    rec.setValue("WEIGHT", ui->weight->text());
    rec.setValue("MOBILEPHOME", ui->phoneNum->text());
    rec.setValue("AGE", date.year() - ui->dateOfBirth->date().year());
    rec.setValue("CREATEDTIMESTAMP", date);

    if (modifyIndex == -1) // 添加操作
        tableModel->insertRecord(tableModel->rowCount(), rec);
    else // 修改操作
        tableModel->setRecord(modifyIndex, rec);

    emit clickBtnSave();
}

void PatientEdit::do_btnCancel()
{
    emit clickBtnCancel();
}
