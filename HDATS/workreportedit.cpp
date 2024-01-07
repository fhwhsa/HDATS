#include "workreportedit.h"
#include "ui_workreportedit.h"

WorkReportEdit::WorkReportEdit(CurrLoginUserInfo *info, QWidget *parent) :
    QWidget(parent),
    info(info),
    ui(new Ui::WorkReportEdit)
{
    ui->setupUi(this);
}

WorkReportEdit::WorkReportEdit(CurrLoginUserInfo *info, QSortFilterProxyModel *sfpm, QModelIndex index, QWidget *parent) :
    QWidget(parent),
    info(info),
    sfpm(sfpm),
    index(index),
    ui(new Ui::WorkReportEdit)
{
    ui->setupUi(this);
}

WorkReportEdit::~WorkReportEdit()
{
    delete ui;
}

void WorkReportEdit::init()
{

}

void WorkReportEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

void WorkReportEdit::do_btnSave()
{

}

void WorkReportEdit::do_btnCancel()
{
    emit clickBtnCancel();
}
