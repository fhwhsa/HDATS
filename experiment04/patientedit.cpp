#include "patientedit.h"
#include "ui_patientedit.h"

PatientEdit::PatientEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientEdit)
{
    ui->setupUi(this);
}

PatientEdit::~PatientEdit()
{
    delete ui;
}
