#include "doctoredit.h"
#include "ui_doctoredit.h"

DoctorEdit::DoctorEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorEdit)
{
    ui->setupUi(this);
}

DoctorEdit::~DoctorEdit()
{
    delete ui;
}
