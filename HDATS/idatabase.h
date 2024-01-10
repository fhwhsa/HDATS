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
#include <QVector>
#include <QVariant>

class IDatabase : public QObject
{
    Q_OBJECT
public:
    // 获取单实例对象
    static IDatabase& GetInstance();

    // 查找是否存在对应用户（医生）
    QVector<QVariant> findUser(QString name, QString passWord);

    // 患者
    QSqlQueryModel* getPatientQueryModel(QWidget *parent); // 获取所有信息
    void filterForPatient(QSqlQueryModel* queryModel, QString filter, QWidget *parent); // 筛选
    void deletePatient(QString id, QWidget *parent); // 删除
    void addPatient(QVector<QVariant> params, QWidget *parent); // 添加
    void modifyPatient(QVector<QVariant> params, QWidget *parent); // 修改

    // 医生
    QSqlQueryModel* getDoctorQueryModel(QWidget *parent);
    void filterForDoctor(QSqlQueryModel *queryModel, QString filter, QWidget *parent);
    void deleteDoctor(QString id, QWidget *parent);
    void addDoctor(QVector<QVariant> params, QWidget *parent);
    void modifyDoctor(QVector<QVariant> params, QWidget *parent);

    // 药品
    QSqlQueryModel* getDrugQueryModel(QWidget *parent);
    void filterForDrug(QSqlQueryModel *queryModel, QString filter, QWidget *parent);
    void deleteDrug(QString id, QWidget *parent);
    void addDrug(QVector<QVariant> params, QWidget *parent);
    void modifyDrug(QVector<QVariant> params, QWidget *parent);
    bool findDrug(QString name); // 查找药品是否存在

    // 诊断记录
    QSqlQueryModel* getDiagnosticRecord(QWidget *parent);
    void filterForDiagnosticRecord(QSqlQueryModel *queryModel, QString filter, QString type, QWidget *parent);
    void deleteDiagnosticRecord(QString id, QWidget *parent);
    QString addDiagnosticRecord(QVector<QVariant> params, QWidget *parent);
    void modifyDiagnosticRecord(QVector<QVariant> params, QWidget *parent);

    // 药品开具记录
    QSqlQueryModel* getMedicationRecords(QWidget *parent);
    void filterForMedicationRecords(QSqlQueryModel *queryModel, QString filter, QWidget *parent);
    void deleteMedicationRecords(QString mrdr_id, QWidget *parent);
    void addMedicationRecords(QVector<QString> nameList, QWidget *parent, QString mrdr_id);

    // 工作报告
    QSqlQueryModel* getWorkReportQueryModel(QWidget *parent);
    void filterForWorkReports(QSqlQueryModel *queryModel, QString filter, QWidget *parent);
    void addWorkReport(QVector<QVariant> params, QWidget *parent);
    void deleteWorkReport(QString wrd_id, QWidget *parent);
    void modifyWorkReport(QVector<QVariant> params, QWidget *parent);

private:
    // 禁止外部构造
    IDatabase();

    // 禁止外部析构
    ~IDatabase();

    // 禁止外部拷贝构造
    IDatabase(const IDatabase &single) = delete;

    // 禁止外部赋值操作
    const IDatabase &operator=(const IDatabase &single) = delete;

    void iniDatabase(); // 初始数据库信息

    QSqlDatabase database;
};

#endif // IDATABASE_H
