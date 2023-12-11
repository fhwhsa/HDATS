#include "patientedit.h"
#include "ui_patientedit.h"

#include <QDebug>

PatientEdit::PatientEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientEdit)
{
    ui->setupUi(this);
}

PatientEdit::~PatientEdit()
{
    qDebug() << "delete PatientEdit";
    delete ui;
}
