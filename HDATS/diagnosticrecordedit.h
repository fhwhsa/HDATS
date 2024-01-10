#ifndef DIAGNOSTICRECORDEDIT_H
#define DIAGNOSTICRECORDEDIT_H

#include "idatabase.h"
#include "patientselectdialog.h"
#include "drugselectdialog.h"
#include "currloginuserinfo.h"

#include <QDebug>
#include <QWidget>
#include <QString>
#include <QVector>
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QSqlQueryModel>
#include <QStringList>
#include <QTableWidgetItem>
#include <QList>
#include <QMessageBox>
#include <QVariant>
#include <QDate>
#include <QHash>

namespace Ui {
class DiagnosticRecordEdit;
}

class DiagnosticRecordEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DiagnosticRecordEdit(CurrLoginUserInfo *info, QString op = "添加", QWidget *parent = nullptr);
    explicit DiagnosticRecordEdit(QSortFilterProxyModel *sfpm, CurrLoginUserInfo *info, QModelIndex i, QString op = "修改", QWidget *parent = nullptr);
    ~DiagnosticRecordEdit();

private:
    Ui::DiagnosticRecordEdit *ui;

    QString operation;

    QSortFilterProxyModel *dr_sfpm;
    CurrLoginUserInfo *info;

    QModelIndex index;

    QVector<QString> patientList;



    void init();
    void iniSignalSlots();

private slots:
    void do_btnPatientSelect();
    void do_PatientSelectFinsh(QString name);
    void do_DrugSelectFinsh(QString name);
    void do_btnDrugAdd();
    void do_btnDrugDelete();
    void do_btnSave();
    void do_btnCancel();
    void do_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

signals:
    void clickBtnCancel();
    void clickBtnSave();
};

#endif // DIAGNOSTICRECORDEDIT_H
