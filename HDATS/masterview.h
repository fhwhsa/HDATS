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

#include <QWidget>

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
    DrugManagement *drugManagement;
    DepartmentManagement *departmentManagement;
    DoctorManagement *doctorManagement;
    PatientManagement *patientManagement;
    PatientEdit *patientEdit;

    void iniSignalSlots();
    void pushToStack(QWidget *w);

private slots:
    void goToLoginView();
    void goToWelcomeView(int pLevel);
    void goToDiagnosticRecords();
    void goToDrugMView();
    void goToDepartmentM();
    void goToDoctorMView();
    void goToPatientMView();
    void goToPatientEditViewForAdd(QSqlQueryModel *tm);
    void goToPatientEditViewForModify(QSqlQueryModel *tm, int index);

    void pageChange(int index);

    void back();
    void loginout();
};
#endif // MASTERVIEW_H
