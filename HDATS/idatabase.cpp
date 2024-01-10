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
        QMessageBox::critical(parent, "患者所有信息查询错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::filterForPatient(QSqlQueryModel* queryModel, QString filter, QWidget *parent)
{
    QString sql = "SELECT P_ID 编号, P_NAME 姓名, P_SEX 性别, TIMESTAMPDIFF(YEAR, P_BIRTHDATE, CURDATE()) 年龄, "
                  "P_MOBILEPHOME 电话号码, HEIGHT 身高, WEIGHT 体重, P_BIRTHDATE 出生日期 FROM patient"
                  " WHERE P_NAME LIKE '%" + filter + "%'";

    queryModel->setQuery(sql);

    if (queryModel->lastError().isValid())
        QMessageBox::critical(parent, "患者信息筛选错误", queryModel->lastError().text());
}

void IDatabase::deletePatient(QString id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM patient WHERE P_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "删除患者信息错误", query.lastError().text());
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
        QMessageBox::critical(parent, "添加患者信息错误", query.lastError().text());
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
        QMessageBox::critical(parent, "修改患者信息错误", query.lastError().text());
}

QSqlQueryModel *IDatabase::getDoctorQueryModel(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT D_ID 编号, D_NAME 姓名, D_SEX 性别, TIMESTAMPDIFF(YEAR, D_BIRTHDATE, CURDATE()) 年龄,"
                         " D_MOBILEPHOME 电话号码, D_BIRTHDATE 出生日期, PCNO 执业证书号, PLevel 权限等级 FROM doctor");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "获取所有医生信息错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::filterForDoctor(QSqlQueryModel *queryModel, QString filter, QWidget *parent)
{
    QString sql = "SELECT D_ID 编号, D_NAME 姓名, D_SEX 性别, TIMESTAMPDIFF(YEAR, D_BIRTHDATE, CURDATE()) 年龄, "
                  "D_MOBILEPHOME 电话号码, D_BIRTHDATE 出生日期, PCNO 执业证书号, PLevel 权限等级 FROM doctor"
                  " WHERE D_NAME LIKE '%" + filter + "%'";

    queryModel->setQuery(sql);

    if (queryModel->lastError().isValid())
        QMessageBox::critical(parent, "筛选医生信息错误", queryModel->lastError().text());

}

void IDatabase::deleteDoctor(QString id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM doctor WHERE D_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "删除医生信息错误", query.lastError().text());
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
        QMessageBox::critical(parent, "添加医生信息错误", query.lastError().text());
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
        QMessageBox::critical(parent, "修改医生信息错误", query.lastError().text());
}

QSqlQueryModel *IDatabase::getDrugQueryModel(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT DRUG_ID 编号, DRUG_NAME 药品名字, DOSE 剂量, INVENTORY 库存, DRUG_INTRODUCTION_TIME 首次引入时间 "
                         "FROM drug");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "获取所有药品信息错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::filterForDrug(QSqlQueryModel *queryModel, QString filter, QWidget *parent)
{
    QString sql = "SELECT DRUG_ID 编号, DRUG_NAME 药品名字, DOSE 剂量, INVENTORY 库存, DRUG_INTRODUCTION_TIME 首次引入时间 FROM drug"
                  " WHERE DRUG_NAME LIKE '%" + filter + "%'";

    queryModel->setQuery(sql);

    if (queryModel->lastError().isValid())
        QMessageBox::critical(parent, "筛选药品信息错误", queryModel->lastError().text());

}

void IDatabase::deleteDrug(QString id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM drug WHERE DRUG_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "删除药品信息错误", query.lastError().text());
}

void IDatabase::addDrug(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "INSERT INTO drug (DRUG_NAME, INVENTORY, DOSE, DRUG_INTRODUCTION_TIME) VALUES (?, ?, ?, ?)";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toInt());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toDate());

    if (!query.exec()) {
        QMessageBox::critical(parent, "添加药品信息错误", query.lastError().text());
        qDebug() << query.lastQuery();
    }
}

void IDatabase::modifyDrug(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "UPDATE drug SET DRUG_NAME = ?, INVENTORY = ?, DOSE = ? WHERE DRUG_ID = ?";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toInt());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toInt());

    if (!query.exec())
        QMessageBox::critical(parent, "修改药品信息错误", query.lastError().text());
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
        QMessageBox::critical(parent, "获取所有诊断记录错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::filterForDiagnosticRecord(QSqlQueryModel *queryModel, QString filter, QString type, QWidget *parent)
{
    QString sql = "SELECT DR_ID 编号, D_NAME 医生姓名, P_NAME 患者姓名, CONTEXT 诊断内容,DATEOFVISIT 创建时间 "
                  "FROM diagnostic_records"
                  " WHERE " + (type == "医生" ? tr(" D_NAME ") : tr(" P_NAME ")) + " LIKE '%" + filter + "%'";

    queryModel->setQuery(sql);

    if (queryModel->lastError().isValid())
        QMessageBox::critical(parent, "筛选诊断记录错误", queryModel->lastError().text());
}

void IDatabase::deleteDiagnosticRecord(QString id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM diagnostic_records WHERE DR_ID = " + id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "删除诊断记录错误", query.lastError().text());
}

QString IDatabase::addDiagnosticRecord(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "SELECT addDiagnosticRecord(?, ?, ?, ?)";


    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toString());
    query.bindValue(2, params[2].toDate());
    query.bindValue(3, params[3].toString());

    if (!query.exec())
    {
        QMessageBox::critical(parent, "添加诊断记录错误", query.lastError().text());
        return "-1";
    }

    if (query.next())
        return query.value(0).toString();
    return "-1";
}

void IDatabase::modifyDiagnosticRecord(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "UPDATE diagnostic_records SET P_NAME = ?, DATEOFVISIT = ?, CONTEXT = ? WHERE DR_ID = ?";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toString());
    query.bindValue(1, params[1].toDate());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toString());

    if (!query.exec())
        QMessageBox::critical(parent, "修改诊断记录错误", query.lastError().text());
}

QSqlQueryModel *IDatabase::getMedicationRecords(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT MRDR_ID, DrugName 药品名字 "
                         "FROM medication_record");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "获取所有诊断记录的开药记录错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::filterForMedicationRecords(QSqlQueryModel *queryModel, QString filter, QWidget *parent)
{
    QString sql = "SELECT MRDR_ID, DrugName 药品名字 "
                  "FROM medication_record"
                  " WHERE MRDR_ID = " + filter;

    queryModel->setQuery(sql);

    if (queryModel->lastError().isValid())
        QMessageBox::critical(parent, "筛选诊断记录的开药记录错误", queryModel->lastError().text());
}

void IDatabase::deleteMedicationRecords(QString mrdr_id, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM medication_record WHERE MRDR_ID = " + mrdr_id);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "删除多条开药记录错误", query.lastError().text());
}

void IDatabase::addMedicationRecords(QVector<QString> nameList, QWidget *parent, QString mrdr_id)
{
    if (nameList.size() == 0)
        return;

    QSqlQuery query;
    QString sql = "INSERT INTO medication_record (MRDR_ID, DrugName) VALUES ";

    sql += "('" + mrdr_id + "','" + nameList[0] + "')";
    for (int i = 1; i < nameList.size(); i++)
        sql += ", ('" + mrdr_id + "','" + nameList[i] + "')";

    query.exec(sql);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "添加多条开药错误", query.lastError().text());
}

QSqlQueryModel *IDatabase::getWorkReportQueryModel(QWidget *parent)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("SELECT WRID, WRD_ID, D_NAME 所属人, CREATETIMESTAMP 创建时间, "
                         "DiagnosisSituation 诊疗情况, TreatmentEffect 治疗效果评估 FROM work_report;");

    if (queryModel->lastError().isValid())
    {
        QMessageBox::critical(parent, "获取所有工作报告错误", queryModel->lastError().text());
        return NULL;
    }

    return queryModel;
}

void IDatabase::filterForWorkReports(QSqlQueryModel *queryModel, QString filter, QWidget *parent)
{
    QString sql = "SELECT WRID, WRD_ID, D_NAME 所属人, CREATETIMESTAMP 创建时间, "
                  "DiagnosisSituation 诊疗情况, TreatmentEffect 治疗效果评估 FROM work_report "
                  "WHERE D_NAME LIKE '%" + filter + "%';";

    queryModel->setQuery(sql);

    if (queryModel->lastError().isValid())
        QMessageBox::critical(parent, "筛选工作报告错误", queryModel->lastError().text());
}

void IDatabase::addWorkReport(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "INSERT INTO work_report (WRD_ID, D_NAME, CREATETIMESTAMP, DiagnosisSituation, TreatmentEffect) VALUES (?, ?, ?, ?, ?)";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toInt());
    query.bindValue(1, params[1].toString());
    query.bindValue(2, params[2].toDate());
    query.bindValue(3, params[3].toString());
    query.bindValue(4, params[4].toString());

    if (!query.exec())
        QMessageBox::critical(parent, "添加工作报告错误", query.lastError().text());
}

void IDatabase::deleteWorkReport(QString wrid, QWidget *parent)
{
    QSqlQuery query;
    query.exec("DELETE FROM work_report WHERE WRID = " + wrid);

    if (query.lastError().isValid())
        QMessageBox::critical(parent, "删除工作报告错误", query.lastError().text());
}

void IDatabase::modifyWorkReport(QVector<QVariant> params, QWidget *parent)
{
    QString sql = "UPDATE work_report SET CREATETIMESTAMP = ?, DiagnosisSituation = ?, TreatmentEffect = ? WHERE WRID = ?";

    QSqlQuery query;
    query.prepare(sql);

    query.bindValue(0, params[0].toDate());
    query.bindValue(1, params[1].toString());
    query.bindValue(2, params[2].toString());
    query.bindValue(3, params[3].toInt());

    if (!query.exec())
        QMessageBox::critical(parent, "修改工作报告错误", query.lastError().text());
}

