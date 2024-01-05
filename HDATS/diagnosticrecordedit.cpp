#include "diagnosticrecordedit.h"
#include "ui_diagnosticrecordedit.h"

DiagnosticRecordEdit::DiagnosticRecordEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiagnosticRecordEdit)
{
    ui->setupUi(this);
}

DiagnosticRecordEdit::~DiagnosticRecordEdit()
{
    delete ui;
}
