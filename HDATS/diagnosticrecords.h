#ifndef DIAGNOSTICRECORDS_H
#define DIAGNOSTICRECORDS_H

#include <QWidget>

namespace Ui {
class DiagnosticRecords;
}

class DiagnosticRecords : public QWidget
{
    Q_OBJECT

public:
    explicit DiagnosticRecords(QWidget *parent = nullptr);
    ~DiagnosticRecords();

private:
    Ui::DiagnosticRecords *ui;
};

#endif // DIAGNOSTICRECORDS_H
