#include "doctoredit.h"
#include "ui_doctoredit.h"

DoctorEdit::DoctorEdit(QSqlQueryModel *qm, int f, QWidget *parent) :
    QWidget(parent),
    queryModel(qm),
    modifyIndex(f),
    ui(new Ui::DoctorEdit)
{
    ui->setupUi(this);

    iniSignalSlots();
    if (f != -1)
        initData();
}

DoctorEdit::~DoctorEdit()
{
    qDebug() << "delete doctorEdit";
    delete ui;
}

QString DoctorEdit::insertPrepare = "INSERT INTO doctor (D_NAME, D_MOBILEPHOME, D_SEX, PLevel, PCNO, D_BIRTHDATE, PASSWORD)"
                                    " VALUES (?, ?, ?, ?, ?, ?, ?)";

QString DoctorEdit::updatePrepare = "UPDATE doctor SET D_NAME = ?, D_MOBILEPHOME = ?, D_SEX = ?, PLevel = ?,"
                                    " PCNO = ?, D_BIRTHDATE = ? WHERE D_ID = ?;";

QString DoctorEdit::initPassWord = "123456";

void DoctorEdit::initData()
{
    QSqlRecord rec = queryModel->record(modifyIndex);
    ui->name->setText(rec.value("姓名").toString());
    ui->gender->setCurrentIndex((rec.value("性别").toString() == "男") ? 0 : 1);
    ui->birthDate->setDate(rec.value("出生日期").toDate());
    ui->phoneNum->setText(rec.value("电话号码").toString());
    ui->pLevel->setCurrentIndex(rec.value("权限等级").toInt() - 1);
    ui->PCNO->setText(rec.value("执业证书号").toString());
}

void DoctorEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

void DoctorEdit::do_btnSave()
{
    QString name = ui->name->text();
    QString mobilePHome = ui->phoneNum->text();
    QString sex = ui->gender->currentText();
    QDate birthDate = ui->birthDate->date();
    int pLevel = ui->pLevel->currentText().toInt();
    QString pcno = ui->PCNO->text();

    if (name.length() == 0 || mobilePHome.length() == 0 || pcno.length() == 0)
    {
        QMessageBox::critical(this, "错误", "不能有为空的信息！");
        return;
    }

    QSqlQuery query;
    if (modifyIndex == -1) // 插入
        query.prepare(insertPrepare);
    else
        query.prepare(updatePrepare);

    query.bindValue(0, name);
    query.bindValue(1, mobilePHome);
    query.bindValue(2, sex);
    query.bindValue(3, pLevel);
    query.bindValue(4, pcno);
    query.bindValue(5, birthDate);
    query.bindValue(6, (modifyIndex == -1) ? initPassWord : queryModel->record(modifyIndex).value("编号"));

    if (!query.exec())
        QMessageBox::critical(this, "错误", query.lastError().text());

    emit clickBtnSave();
}

void DoctorEdit::do_btnCancel()
{

    emit clickBtnCancel();
}
