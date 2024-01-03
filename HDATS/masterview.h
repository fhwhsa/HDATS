#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include "login.h"
#include "welcome.h"
#include "drugmanagement.h"
#include "doctormanagement.h"
#include "patientmanagement.h"
#include "patientedit.h"
#include "diagnosticrecords.h"
#include "departmentmanagement.h"
#include "doctoredit.h"
#include "drugedit.h"

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
    DiagnosticRecords *diagnosticRecords;
    DepartmentManagement *departmentManagement;

    DoctorManagement *doctorManagement;
    DoctorEdit *doctorEdit;

    PatientManagement *patientManagement;
    PatientEdit *patientEdit;

    DrugManagement *drugManagement;
    DrugEdit *drugEdit;

    void iniSignalSlots();
    void pushToStack(QWidget *w);

private slots:
    void goToLoginView();

    void goToWelcomeView(int pLevel);

    void goToDiagnosticRecords();

    void goToDepartmentM();

    void goToDoctorMView();
    void goToDoctorEditViewForAdd();
    void goToDoctorEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index);

    void goToPatientMView();
    void goToPatientEditViewForAdd();
    void goToPatientEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index);

    void goToDrugMView();
    void goToDrugEditViewForAdd();
    void goToDrugEditViewForModify(QSortFilterProxyModel *sfpm, QModelIndex index);

    void pageChange(int index);

    void back();
    void loginout();
};
#endif // MASTERVIEW_H
