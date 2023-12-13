#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include "login.h"
#include "welcome.h"
#include "departmentmanagement.h"
#include "doctormanagement.h"
#include "patientmanagement.h"
#include "patientedit.h"

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
    DepartmentManagement *departmentManagement;
    DoctorManagement *doctorManagement;
    PatientManagement *patientManagement;
    PatientEdit *patientEdit;

    void iniSignalSlots();
    void pushToStack(QWidget *w);

private slots:
    void goToLoginView();
    void goToWelcomeView();
    void goToDepartmentMView();
    void goToDoctorMView();
    void goToPatientMView();
    void goToPatientEditViewForAdd(QSqlTableModel *tm);
    void goToPatientEditViewForModify(QSqlTableModel *tm, int index);

    void pageChange(int index);

    void back();
    void loginout();
};
#endif // MASTERVIEW_H
