#include "diagnosticrecords.h"
#include "ui_diagnosticrecords.h"

#include <QDebug>

DiagnosticRecords::DiagnosticRecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiagnosticRecords)
{
    ui->setupUi(this);
}

DiagnosticRecords::~DiagnosticRecords()
{
    qDebug() << "delete DiagnosticRecords";
    delete ui;
}
