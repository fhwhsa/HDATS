#ifndef PATIENTEDIT_H
#define PATIENTEDIT_H

#include <QWidget>

namespace Ui {
class PatientEdit;
}

class PatientEdit : public QWidget
{
    Q_OBJECT

public:
    explicit PatientEdit(QWidget *parent = nullptr);
    ~PatientEdit();

private:
    Ui::PatientEdit *ui;
};

#endif // PATIENTEDIT_H
