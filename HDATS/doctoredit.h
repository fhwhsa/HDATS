#ifndef DOCTOREDIT_H
#define DOCTOREDIT_H

#include <QWidget>

namespace Ui {
class DoctorEdit;
}

class DoctorEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorEdit(QWidget *parent = nullptr);
    ~DoctorEdit();

private:
    Ui::DoctorEdit *ui;
};

#endif // DOCTOREDIT_H
