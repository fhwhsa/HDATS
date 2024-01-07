#include "diagnosticrecordedit.h"
#include "ui_diagnosticrecordedit.h"

DiagnosticRecordEdit::DiagnosticRecordEdit(CurrLoginUserInfo *info, QString op, QWidget *parent) :
    QWidget(parent),
    info(info),
    operation(op),
    ui(new Ui::DiagnosticRecordEdit)
{
    ui->setupUi(this);
    init();
    iniSignalSlots();
}

DiagnosticRecordEdit::DiagnosticRecordEdit(QSortFilterProxyModel *sfpm, CurrLoginUserInfo *info, QModelIndex i, QString op, QWidget *parent) :
    QWidget(parent),
    dr_sfpm(sfpm),
    info(info),
    index(i),
    operation(op),
    ui(new Ui::DiagnosticRecordEdit)
{
    ui->setupUi(this);
    init();
    iniSignalSlots();
}

DiagnosticRecordEdit::~DiagnosticRecordEdit()
{
    qDebug() << "delete DiagnosticRecordEdit";
    delete ui;
}

void DiagnosticRecordEdit::init()
{
    QStringList header;
    header << "药品名";
    ui->tableWidget->setColumnCount(header.size());
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->verticalHeader()->hide();

    ui->btnDrugDelete->setEnabled(false);

    if (operation == "修改")
    {
        ui->btnPatientSelect->setText(dr_sfpm->data(index.siblingAtColumn(2)).toString());
        ui->context->setPlainText(dr_sfpm->data(index.siblingAtColumn(3)).toString());
        ui->dateEdit->setDate(dr_sfpm->data(index.siblingAtColumn(4)).toDate());

        QSqlQueryModel *mrQueryModel = IDatabase::GetInstance().getMedicationRecords(this);
        IDatabase::GetInstance().filterForMedicationRecords(mrQueryModel, dr_sfpm->data(index.siblingAtColumn(0)).toString(), this);

        for (int i = 0; i < mrQueryModel->rowCount(); i++)
        {
            int pos = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(pos);
            ui->tableWidget->setItem(pos, 0, new QTableWidgetItem(mrQueryModel->record(i).value("药品名字").toString()));
        }
    }

}

void DiagnosticRecordEdit::iniSignalSlots()
{
    connect(ui->btnPatientSelect, SIGNAL(clicked()), this, SLOT(do_btnPatientSelect()));
    connect(ui->btnDrugAdd, SIGNAL(clicked()), this, SLOT(do_btnDrugAdd()));
    connect(ui->btnDrugDelete, SIGNAL(clicked()), this, SLOT(do_btnDrugDelete()));
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
    connect(ui->tableWidget, &QTableWidget::currentCellChanged, this, &DiagnosticRecordEdit::do_currentCellChanged);
}

void DiagnosticRecordEdit::do_btnPatientSelect()
{
    // 打开窗口挑选
    PatientSelectDialog* patientSelectDialog = new PatientSelectDialog;
    connect(patientSelectDialog, &PatientSelectDialog::selected, this, &DiagnosticRecordEdit::do_PatientSelectFinsh);
    patientSelectDialog->exec();
}

void DiagnosticRecordEdit::do_PatientSelectFinsh(QString name)
{
    ui->btnPatientSelect->setText(name); // 显示在按钮上
}

void DiagnosticRecordEdit::do_DrugSelectFinsh(QString name)
{
    int pos = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(pos);
    ui->tableWidget->setItem(pos, 0, new QTableWidgetItem(name));
}

void DiagnosticRecordEdit::do_btnDrugAdd()
{
    DrugSelectDialog* drugSelectDialog = new DrugSelectDialog;
    connect(drugSelectDialog, &DrugSelectDialog::selected, this, &DiagnosticRecordEdit::do_DrugSelectFinsh);
    drugSelectDialog->exec();
}

void DiagnosticRecordEdit::do_btnDrugDelete()
{
    int pos = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(pos);

    if (ui->tableWidget->rowCount() == 0)
        ui->btnDrugDelete->setEnabled(false);
}

//SELECT DR_ID 编号, D_NAME 医生姓名, P_NAME 患者姓名, CONTEXT 诊断内容,DATEOFVISIT 创建时间 FROM diagnostic_records
//INSERT INTO diagnostic_records (D_NAME, P_NAME, DATEOFVISIT, CONTEXT) VALUES (?, ?, ?, ?, ?)
//UPDATE diagnostic_records SET P_NAME = ?, DATEOFVISIT = ?, CONTEXT = ? WHERE DR_ID = ?
void DiagnosticRecordEdit::do_btnSave()
{
    QString pname = ui->btnPatientSelect->text();

    if (pname == "选择")
    {
        QMessageBox::critical(this, "错误", "未选择患者");
        return;
    }

    QDate dateOfVisit = ui->dateEdit->date();
    QString context = ui->context->toPlainText();

    QVector<QVariant> params;
    QVector<QString> drugNameList;

    IDatabase& instance = IDatabase::GetInstance();

    if (operation == "添加")
    {
        params.push_back(info->getUserName());
        params.push_back(pname);
        params.push_back(dateOfVisit);
        params.push_back(context);

        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            qDebug() << ui->tableWidget->item(i, 0)->text();
            drugNameList.push_back(ui->tableWidget->item(i, 0)->text());
        }

        QString t = instance.addDiagnosticRecord(params, this);
        instance.addMedicationRecords(drugNameList, this, t);
    }

    else
    {
        QString mrdr_id = dr_sfpm->data(index.siblingAtColumn(0)).toString();

        params.push_back(pname);
        params.push_back(dateOfVisit);
        params.push_back(context);
        params.push_back(mrdr_id);

        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            qDebug() << ui->tableWidget->item(i, 0)->text();
            drugNameList.push_back(ui->tableWidget->item(i, 0)->text());
        }

        instance.modifyDiagnosticRecord(params, this);
        instance.deleteMedicationRecords(mrdr_id, this);
        instance.addMedicationRecords(drugNameList, this, mrdr_id);
    }

    emit clickBtnSave();
}

void DiagnosticRecordEdit::do_btnCancel()
{
    emit clickBtnCancel();
}

void DiagnosticRecordEdit::do_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    ui->btnDrugDelete->setEnabled(true);
}

