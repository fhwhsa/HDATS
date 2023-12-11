#ifndef DOCTORMANAGEMENT_H
#define DOCTORMANAGEMENT_H

#include <QWidget>

namespace Ui {
class DoctorManagement;
}

class DoctorManagement : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorManagement(QWidget *parent = nullptr);
    ~DoctorManagement();

private:
    Ui::DoctorManagement *ui;
};

#endif // DOCTORMANAGEMENT_H
