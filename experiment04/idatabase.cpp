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
    database.setDatabaseName("lab4a");
    database.setUserName("root");
    database.setPassword("fws@fws-workstation");
    if (database.open())
        qDebug() << "Database connect success";
    else
        qDebug() << "Database connect failed";
}

bool IDatabase::findUser(QString userName, QString passWord)
{
    QString sql = "select count(*) cnt from user where username = '" + userName + "' and password = '" + passWord + "';";
//    qDebug() << sql;
    QSqlQuery res = database.exec(sql);
    if (!res.first()) return false;
    return res.value("cnt").toInt() == 1;
}

QSqlTableModel* IDatabase::getPatientTableModel(QWidget *parent)
{
    QSqlTableModel *tableModel = new QSqlTableModel(this, database);
    tableModel->setTable("patient");
    tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    tableModel->setSort(tableModel->fieldIndex("ID"), Qt::AscendingOrder);

    if (!(tableModel->select())) {
        QMessageBox::critical(parent, "错误", tableModel->lastError().text());
        return NULL;
    }

    tableModel->setHeaderData(tableModel->fieldIndex("ID"), Qt::Horizontal, "编号");
    tableModel->setHeaderData(tableModel->fieldIndex("ID_CARD"), Qt::Horizontal, "身份证号");
    tableModel->setHeaderData(tableModel->fieldIndex("NAME"), Qt::Horizontal, "姓名");
    tableModel->setHeaderData(tableModel->fieldIndex("SEX"), Qt::Horizontal, "性别");
    tableModel->setHeaderData(tableModel->fieldIndex("DOB"), Qt::Horizontal, "诊断");
    tableModel->setHeaderData(tableModel->fieldIndex("HEIGHT"), Qt::Horizontal, "身高");
    tableModel->setHeaderData(tableModel->fieldIndex("WEIGHT"), Qt::Horizontal, "体重");
    tableModel->setHeaderData(tableModel->fieldIndex("MOBILEPHOME"), Qt::Horizontal, "电话号码");
    tableModel->setHeaderData(tableModel->fieldIndex("AGE"), Qt::Horizontal, "年龄");
    tableModel->setHeaderData(tableModel->fieldIndex("CREATEDTIMESTAMP"), Qt::Horizontal, "创建时间");

    return tableModel;
}
