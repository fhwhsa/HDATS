#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include "login.h"
#include "welcome.h"
#include "drugmanagement.h"
#include "doctormanagement.h"
#include "patientmanagement.h"
#include "patientedit.h"
#include "diagnosticrecord.h"
#include "doctoredit.h"
#include "drugedit.h"
#include "currloginuserinfo.h"
#include "diagnosticrecordedit.h"
#include "workreportmanagement.h"
#include "workreportedit.h"

#include <QWidget>
#include <QSortFilterProxyModel>
#include <QModelIndex>


QT_BEGIN_NAMESPACE
namespace Ui { class MasterView; }
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

private:
    Ui::MasterView *ui;

    Login *login;
    Welcome *welcome;

    DoctorManagement *doctorManagement;
    DoctorEdit *doctorEdit;

    PatientManagement *patientManagement;
    PatientEdit *patientEdit;

    DrugManagement *drugManagement;
    DrugEdit *drugEdit;

    DiagnosticRecord *diagnosticRecord;
    DiagnosticRecordEdit *diagnosticRecordEdit;

    WorkReportManagement *workReportManagement;
    WorkReportEdit *workReportEdit;


    void iniSignalSlots();
    void pushToStack(QWidget *w);

private slots:
    void goToLoginView();

    void goToWelcomeView(CurrLoginUserInfo *info);

    void goToDoctorMView();
    void goToDoctorEditViewForAdd();
    void goToDoctorEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index);

    void goToPatientMView();
    void goToPatientEditViewForAdd();
    void goToPatientEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index);

    void goToDrugMView();
    void goToDrugEditViewForAdd();
    void goToDrugEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index);

    void goToDiagnosticRecord(CurrLoginUserInfo *info);
    void goToDiagnosticRecordForAdd(CurrLoginUserInfo *info);
    void goToDiagnosticRecordForModify(QSortFilterProxyModel *sfpm, CurrLoginUserInfo *info, QModelIndex index);

    void goToWorkReportMView(CurrLoginUserInfo *info);
    void goToWorkReportEditViewForAdd(CurrLoginUserInfo *info);
    void goToWorkReportEditViewForModify(CurrLoginUserInfo *info, QSortFilterProxyModel *sfpm, QModelIndex index);

    void pageChange(int index);

    void back();
    void loginout();
};
#endif // MASTERVIEW_H
