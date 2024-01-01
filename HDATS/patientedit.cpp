#include "patientedit.h"
#include "ui_patientedit.h"

#include <QDebug>

PatientEdit::PatientEdit(QSqlQueryModel *qm, int f, QWidget *parent) :
    QWidget(parent),
    queryModel(qm),
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

QString PatientEdit::insertPrepare = "INSERT INTO patient (P_NAME, P_MOBILEPHOME, P_SEX, HEIGHT, WEIGHT, P_BIRTHDATE) VALUES ( ?, ?, ?, ?, ?, ?)";
QString PatientEdit::updatePrepare = "UPDATE patient SET P_NAME = ?, P_MOBILEPHOME = ?, P_SEX = ?, HEIGHT = ?, WEIGHT = ?, P_BIRTHDATE = ? WHERE P_ID = ?";

void PatientEdit::initData()
{
    QSqlRecord rec = queryModel->record(modifyIndex);
    ui->name->setText(rec.value("姓名").toString());
    ui->gender->setCurrentIndex((rec.value("性别").toString() == "男") ? 0 : 1);
    ui->birthDate->setDate(rec.value("出生日期").toDate());
    ui->height->setValue(rec.value("身高").toDouble());
    ui->weight->setValue(rec.value("体重").toDouble());
    ui->phoneNum->setText(rec.value("电话号码").toString());
}

void PatientEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

void PatientEdit::do_btnSave()
{
    QString P_NAME = ui->name->text();
    QString P_MOBILEPHOME = ui->phoneNum->text();
    QString P_SEX = ui->gender->currentText();
    double HEIGHT = ui->height->text().toDouble();
    double WEIGHT = ui->weight->text().toDouble();
    QDate P_BIRTHDATE = ui->birthDate->date();


    QSqlQuery query;
    if (modifyIndex == -1)
        query.prepare(insertPrepare);
    else // 修改操作
        query.prepare(updatePrepare);

    query.bindValue(0, P_NAME);
    query.bindValue(1, P_MOBILEPHOME);
    query.bindValue(2, P_SEX);
    query.bindValue(3, HEIGHT);
    query.bindValue(4, WEIGHT);
    query.bindValue(5, P_BIRTHDATE);
    if (modifyIndex != -1)
    {
        QSqlRecord rec = queryModel->record(modifyIndex);
        query.bindValue(6, rec.value("编号").toString());
    }

    if (!query.exec())
        QMessageBox::critical(this, "错误", query.lastError().text());

    emit clickBtnSave();
}

void PatientEdit::do_btnCancel()
{
    emit clickBtnCancel();
}
