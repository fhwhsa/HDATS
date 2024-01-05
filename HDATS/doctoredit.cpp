#include "doctoredit.h"
#include "ui_doctoredit.h"

#include "idatabase.h"

DoctorEdit::DoctorEdit(QString op, QWidget *parent) :
    QWidget(parent),
    operation(op),
    ui(new Ui::DoctorEdit)
{
    ui->setupUi(this);

    iniSignalSlots();
}

DoctorEdit::DoctorEdit(QSortFilterProxyModel *sfpm, QModelIndex i, QString op, QWidget *parent) :
    QWidget(parent),
    sfpm(sfpm),
    index(i),
    operation(op),
    ui(new Ui::DoctorEdit)
{
    ui->setupUi(this);

    initData();
    iniSignalSlots();
}

DoctorEdit::~DoctorEdit()
{
    qDebug() << "delete doctorEdit";
    delete ui;
}

QString DoctorEdit::initPassWord = "123456";

void DoctorEdit::initData()
{
    ui->name->setText(sfpm->data(index.siblingAtColumn(1)).toString());
    ui->gender->setCurrentIndex((sfpm->data(index.siblingAtColumn(2)).toString() == "男") ? 0 : 1);
    ui->birthDate->setDate(sfpm->data(index.siblingAtColumn(5)).toDate());
    ui->phoneNum->setText(sfpm->data(index.siblingAtColumn(4)).toString());
    ui->pLevel->setCurrentIndex(sfpm->data(index.siblingAtColumn(7)).toInt() - 1);
    ui->PCNO->setText(sfpm->data(index.siblingAtColumn(6)).toString());

}

void DoctorEdit::iniSignalSlots()
{
    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(do_btnSave()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(do_btnCancel()));
}

//"INSERT INTO doctor (D_NAME, D_MOBILEPHOME, D_SEX, PLevel, PCNO, D_BIRTHDATE, PASSWORD) VALUES (?, ?, ?, ?, ?, ?, ?)";
//"UPDATE doctor SET D_NAME = ?, D_MOBILEPHOME = ?, D_SEX = ?, PLevel = ?, PCNO = ?, D_BIRTHDATE = ? WHERE D_ID = ?;";
void DoctorEdit::do_btnSave()
{
    QString name = ui->name->text();
    QString mobilePHome = ui->phoneNum->text();
    QString sex = ui->gender->currentText();
    QDate birthDate = ui->birthDate->date();
    int pLevel = ui->pLevel->currentText().toInt();
    QString pcno = ui->PCNO->text();

    if (name.length() == 0 || mobilePHome.length() == 0 || pcno.length() == 0)
    {
        QMessageBox::critical(this, "错误", "信息填写不完整");
        return;
    }

    QVector<QVariant> params;

    params.push_back(name);
    params.push_back(mobilePHome);
    params.push_back(sex);
    params.push_back(pLevel);
    params.push_back(pcno);
    params.push_back(birthDate);

    IDatabase& instance = IDatabase::GetInstance();
    if (operation == "添加")
    {
        params.push_back(initPassWord);
        instance.addDoctor(params, this);
    }
    else
    {
        params.push_back(sfpm->data(index.siblingAtColumn(0)).toString());
        instance.modifyDoctor(params, this);
    }

    emit clickBtnSave();
}

void DoctorEdit::do_btnCancel()
{

    emit clickBtnCancel();
}
