#include "patientedit.h"
#include "ui_patientedit.h"

#include "idatabase.h"

#include <QDebug>

PatientEdit::PatientEdit(QString op, QWidget *parent) :
    QWidget(parent),
    operation(op),
    ui(new Ui::PatientEdit)
{
    ui->setupUi(this);
    iniSignalSlots();
}

PatientEdit::PatientEdit(QSortFilterProxyModel *sfpm, QModelIndex i, QString op, QWidget *parent) :
    QWidget(parent),
    sfpm(sfpm),
    index(i),
    operation(op),
    ui(new Ui::PatientEdit)
{
    ui->setupUi(this);
    initData();
    iniSignalSlots();
}

PatientEdit::~PatientEdit()
{
    qDebug() << "delete PatientEdit";
    delete ui;
}

void PatientEdit::initData()
{
    ui->name->setText(sfpm->data(index.siblingAtColumn(1)).toString());
    ui->gender->setCurrentIndex((sfpm->data(index.siblingAtColumn(2)).toString() == "男") ? 0 : 1);
    ui->birthDate->setDate(sfpm->data(index.siblingAtColumn(7)).toDate());
    ui->height->setValue(sfpm->data(index.siblingAtColumn(5)).toDouble());
    ui->weight->setValue(sfpm->data(index.siblingAtColumn(6)).toDouble());
    ui->phoneNum->setText(sfpm->data(index.siblingAtColumn(4)).toString());
}

void PatientEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}


//"INSERT INTO patient (P_NAME, P_MOBILEPHOME, P_SEX, HEIGHT, WEIGHT, P_BIRTHDATE) VALUES ( ?, ?, ?, ?, ?, ?)";
//"UPDATE patient SET P_NAME = ?, P_MOBILEPHOME = ?, P_SEX = ?, HEIGHT = ?, WEIGHT = ?, P_BIRTHDATE = ? WHERE P_ID = ?";
void PatientEdit::do_btnSave()
{
    QString P_NAME = ui->name->text();
    QString P_MOBILEPHOME = ui->phoneNum->text();
    QString P_SEX = ui->gender->currentText();
    double HEIGHT = ui->height->text().toDouble();
    double WEIGHT = ui->weight->text().toDouble();
    QDate P_BIRTHDATE = ui->birthDate->date();

    if (P_NAME.length() == 0 || P_MOBILEPHOME.length() == 0)
    {
        QMessageBox::critical(this, "错误", "信息填写不完整");
        return;
    }

    QVector<QVariant> params;
    params.push_back(P_NAME);
    params.push_back(P_MOBILEPHOME);
    params.push_back(P_SEX);
    params.push_back(HEIGHT);
    params.push_back(WEIGHT);
    params.push_back(P_BIRTHDATE);

    IDatabase& instance = IDatabase::GetInstance();
    if (operation == "添加")
        instance.addPatient(params, this);
    else
    {
        params.push_back(sfpm->data(index.siblingAtColumn(0)).toInt());
        instance.modifyPatient(params, this);
    }

    emit clickBtnSave();
}

void PatientEdit::do_btnCancel()
{
    emit clickBtnCancel();
}
