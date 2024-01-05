#include "idatabase.h"

#include <QDebug>

IDatabase::IDatabase()
{
    iniDatabase();
}

IDatabase::~IDatabase()
{

}

IDatabase& IDatabase::GetInstance()
{
    static IDatabase single;
    return single;
}

void IDatabase::iniDatabase()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setPort(3306);
    database.setDatabaseName("hdats");
    database.setUserName("root");
    database.setPassword("fws@fws-workstation");
    if (database.open())
        qDebug() << "Database connect success";
    else
        qDebug() << "Database connect failed";
}

QVector<QVariant> IDatabase::findUser(QString name, QString passWord)
{
    QString sql = "select * from doctor where D_NAME = '" + name + "' and PASSWORD = '" + passWord + "';";
//    qDebug() << sql;
    QSqlQuery query = database.exec(sql);

    QVector<QVariant> res;
    if (!query.first())
        res.push_back(false);
    else
    {
        res.push_back(true);
        res.push_back(query.value("D_ID").toInt());
        res.push_back(query.value("D_NAME").toString());
        res.push_back(query.value("PLevel").toInt());
    }

    return res;
}


QSqlQueryModel *IDatabase::getPatientQueryModel(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT P_ID 编号, P_NAME 姓名, P_SEX 性别, TIMESTAMPDIFF(YEAR, P_BIRTHDATE, CURDATE()) 年龄, "
                         "P_MOBILEPHOME 电话号码, HEIGHT 身高, WEIGHT 体重, P_BIRTHDATE 出生日期 FROM patient");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::deletePatient(QString id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM patient WHERE P_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

void IDatabase::addPatient(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "INSERT INTO patient (P_NAME, P_MOBILEPHOME, P_SEX, HEIGHT, WEIGHT, P_BIRTHDATE) "
                  "VALUES ( ?, ?, ?, ?, ?, ?)";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toString());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toDouble());
    query.bindValue(4, params[4].toDouble());
    query.bindValue(5, params[5].toDate());

    if (!query.exec())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

void IDatabase::modifyPatient(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "UPDATE patient SET P_NAME = ?, P_MOBILEPHOME = ?, P_SEX = ?, "
                  "HEIGHT = ?, WEIGHT = ?, P_BIRTHDATE = ? WHERE P_ID = ?";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toString());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toDouble());
    query.bindValue(4, params[4].toDouble());
    query.bindValue(5, params[5].toDate());
    query.bindValue(6, params[6].toInt());

    if (!query.exec())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

QSqlQueryModel *IDatabase::getDoctorQueryModel(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT D_ID 编号, D_NAME 姓名, D_SEX 性别, TIMESTAMPDIFF(YEAR, D_BIRTHDATE, CURDATE()) 年龄,"
                         " D_MOBILEPHOME 电话号码, D_BIRTHDATE 出生日期, PCNO 执业证书号, PLevel 权限等级 FROM doctor");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::deleteDoctor(QString id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM doctor WHERE D_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

void IDatabase::addDoctor(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "INSERT INTO doctor (D_NAME, D_MOBILEPHOME, D_SEX, PLevel, PCNO, D_BIRTHDATE, PASSWORD)"
                                        " VALUES (?, ?, ?, ?, ?, ?, ?)";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toString());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toInt());
    query.bindValue(4, params[4].toString());
    query.bindValue(5, params[5].toDate());

    query.bindValue(6, params[6].toString());

    if (!query.exec())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

void IDatabase::modifyDoctor(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "UPDATE doctor SET D_NAME = ?, D_MOBILEPHOME = ?, D_SEX = ?, PLevel = ?,"
                                        " PCNO = ?, D_BIRTHDATE = ? WHERE D_ID = ?;";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toString());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toInt());
    query.bindValue(4, params[4].toString());
    query.bindValue(5, params[5].toDate());

    query.bindValue(6, params[6].toInt());

    if (!query.exec())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

QSqlQueryModel *IDatabase::getDrugQueryModel(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT DRUG_ID 编号, DRUG_NAME 药品名字, INVENTORY 库存, DRUG_INTRODUCTION_TIME 首次引入时间 "
                         "FROM drug");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::deleteDrug(QString id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM drug WHERE DRUG_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

void IDatabase::addDrug(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "INSERT INTO drug (DRUG_NAME, INVENTORY, DRUG_INTRODUCTION_TIME) VALUES (?, ?, ?)";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toInt());

    query.bindValue(2, params[2].toDate());

    if (!query.exec())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

void IDatabase::modifyDrug(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "UPDATE drug SET DRUG_NAME = ?, INVENTORY = ? WHERE DRUG_ID = ?";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toInt());

    query.bindValue(2, params[2].toInt());

    if (!query.exec())
        QMessageBox::critical(parent, "错误", query.lastError().text());
}

bool IDatabase::findDrug(QString name)
{
    QString sql = "SELECT * FROM drug WHERE DRUG_NAME = '" + name + "';";
    QSqlQuery res = database.exec(sql);
    return res.first();
}

QSqlQueryModel *IDatabase::getDiagnosticRecord(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT DR_ID 编号, D_NAME 医生姓名, P_NAME 患者姓名, CONTEXT 诊断内容,DATEOFVISIT 创建时间 "
                         "FROM diagnostic_records");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

QSqlQueryModel *IDatabase::getMedicationRecords(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT MRDR_ID, MRDRUG_ID, d.DRUG_NAME 药品名字, dose 剂量 "
                         "FROM medication_record mr INNER JOIN drug d ON mr.MRDRUG_ID = d.DRUG_ID");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

