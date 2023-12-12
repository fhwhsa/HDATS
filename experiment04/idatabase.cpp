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
        qDebug() << "success";
    else
        qDebug() << "failed";
}

bool IDatabase::findUser(QString userName, QString passWord)
{
    QString sql = "select count(*) cnt from user where username = '" + userName + "' and password = '" + passWord + "';";
//    qDebug() << sql;
    QSqlQuery res = database.exec(sql);
    if (!res.first()) return false;
    return res.value("cnt").toInt() == 1;
}
