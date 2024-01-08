#include "workreportedit.h"
#include "ui_workreportedit.h"

WorkReportEdit::WorkReportEdit(CurrLoginUserInfo *info, QString op, QWidget *parent) :
    QWidget(parent),
    info(info),
    operation(op),
    ui(new Ui::WorkReportEdit)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

WorkReportEdit::WorkReportEdit(CurrLoginUserInfo *info, QSortFilterProxyModel *sfpm, QModelIndex index, QString op, QWidget *parent) :
    QWidget(parent),
    info(info),
    sfpm(sfpm),
    index(index),
    operation(op),
    ui(new Ui::WorkReportEdit)
{
    ui->setupUi(this);

    init();
    iniSignalSlots();
}

WorkReportEdit::~WorkReportEdit()
{
    delete ui;
}

void WorkReportEdit::init()
{
    if (operation == "添加")
        ui->dateEdit->setDate(QDate::currentDate());
    else
    {
        ui->dateEdit->setDate(sfpm->data(index.siblingAtColumn(3)).toDate());
        ui->diagnosisSituation->setPlainText(sfpm->data(index.siblingAtColumn(4)).toString());
        ui->treatmentEffect->setPlainText(sfpm->data(index.siblingAtColumn(5)).toString());
    }
}

void WorkReportEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

// INSERT INTO work_report (WRD_ID, D_NAME, CREATETIMESTAMP, DiagnosisSituation, TreatmentEffect) VALUES (?, ?, ?, ?, ?)
// UPDATE work_report SET CREATETIMESTAMP = ?, DiagnosisSituation = ?, TreatmentEffect = ? WHERE WRID = ?
void WorkReportEdit::do_btnSave()
{
    QDate inputDate = ui->dateEdit->date();
    QString dia = ui->diagnosisSituation->toPlainText();
    QString tre = ui->treatmentEffect->toPlainText();

    QVector<QVariant> params;

    if (operation == "添加")
    {
        params.push_back(info->getUserID());
        params.push_back(info->getUserName());
    }

    params.push_back(inputDate);
    params.push_back(dia);
    params.push_back(tre);

    if (operation == "修改")
    {
        params.push_back(sfpm->data(index.siblingAtColumn(0)).toInt());
        IDatabase::GetInstance().modifyWorkReport(params, this);
    }
    else
        IDatabase::GetInstance().addWorkReport(params, this);

    emit clickBtnSave();
}

void WorkReportEdit::do_btnCancel()
{
    emit clickBtnCancel();
}
