#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QWidget>
#include <QPair>
#include <QSqlQueryModel>
#include <QSqlRecord>

class IDatabase : public QObject
{
    Q_OBJECT
public:
    // 获取单实例对象
    static IDatabase& GetInstance();

    // 查找是否存在对应用户（医生）
    QPair<bool, int> findUser(QString name, QString passWord);

    // 患者表
    QSqlQueryModel* getPatientQueryModel(QWidget *parent);

    // 医生表
    QSqlQueryModel* getDoctorQueryModel(QWidget *parent);

private:
    // 禁止外部构造
    IDatabase();

    // 禁止外部析构
    ~IDatabase();

    // 禁止外部拷贝构造
    IDatabase(const IDatabase &single) = delete;

    // 禁止外部赋值操作
    const IDatabase &operator=(const IDatabase &single) = delete;

    void iniDatabase();

    QSqlDatabase database;
};

#endif // IDATABASE_H
