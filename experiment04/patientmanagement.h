#ifndef PATIENTMANAGEMENT_H
#define PATIENTMANAGEMENT_H

#include <QWidget>

namespace Ui {
class PatientManagement;
}

class PatientManagement : public QWidget
{
    Q_OBJECT

public:
    explicit PatientManagement(QWidget *parent = nullptr);
    ~PatientManagement();

private:
    Ui::PatientManagement *ui;

    void iniSignalSlots();

signals:
    void add();
};

#endif // PATIENTMANAGEMENT_H
