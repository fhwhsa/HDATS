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

QPair<bool, int> IDatabase::findUser(QString name, QString passWord)
{
    QString sql = "select * from doctor where D_NAME = '" + name + "' and PASSWORD = '" + passWord + "';";
//    qDebug() << sql;
    QSqlQuery res = database.exec(sql);

    if (!res.first())
        return QPair(false, 0);

    return QPair(true, res.value("PLevel").toInt());
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

QSqlQueryModel *IDatabase::getDrugQueryModel(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT DRUG_ID 编号, DRUG_NAME 药品名字, INVENTORY 库存, DRUG_INTRODUCTION_TIME 首次引入时间 FROM drug");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

bool IDatabase::findDrug(QString name)
{
    QString sql = "SELECT * FROM drug WHERE DRUG_NAME = '" + name + "';";
    QSqlQuery res = database.exec(sql);
    return res.first();
}


