#ifndef DIAGNOSTICRECORDEDIT_H
#define DIAGNOSTICRECORDEDIT_H

#include <QWidget>

namespace Ui {
class DiagnosticRecordEdit;
}

class DiagnosticRecordEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DiagnosticRecordEdit(QWidget *parent = nullptr);
    ~DiagnosticRecordEdit();

private:
    Ui::DiagnosticRecordEdit *ui;
};

#endif // DIAGNOSTICRECORDEDIT_H
