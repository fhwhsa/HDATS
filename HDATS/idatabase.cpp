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

QSqlTableModel* IDatabase::getPatientTableModel(QWidget *parent)
{
    QSqlTableModel *tableModel = new QSqlTableModel(parent, database);
    tableModel->setTable("patient");

    tableModel->setEditStrategy(QSqlTableModel::OnFieldChange); // 字段值变化时立即更新到数据库
    tableModel->setSort(tableModel->fieldIndex("ID"), Qt::AscendingOrder);

    if (!(tableModel->select())) {
        QMessageBox::critical(parent, "错误", tableModel->lastError().text());
        return NULL;
    }

    tableModel->setHeaderData(tableModel->fieldIndex("P_NAME"), Qt::Horizontal, "姓名");
    tableModel->setHeaderData(tableModel->fieldIndex("P_MOBILEPHOME"), Qt::Horizontal, "电话号码");
    tableModel->setHeaderData(tableModel->fieldIndex("P_SEX"), Qt::Horizontal, "性别");
    tableModel->setHeaderData(tableModel->fieldIndex("P_AGE"), Qt::Horizontal, "年龄");
    tableModel->setHeaderData(tableModel->fieldIndex("HEIGHT"), Qt::Horizontal, "身高");
    tableModel->setHeaderData(tableModel->fieldIndex("WEIGHT"), Qt::Horizontal, "体重");


    return tableModel;
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
