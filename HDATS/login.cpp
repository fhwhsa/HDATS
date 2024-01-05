#include "login.h"
#include "idatabase.h"
#include "ui_login.h"
#include "currloginuserinfo.h"

#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    iniSignalSlots();
}

Login::~Login()
{
    qDebug() << "delete login";
    delete ui;
}

void Login::iniSignalSlots()
{
    connect(ui->btnLogin, SIGNAL(clicked()), this, SLOT(check()));
}

void Login::check()
{
    QString name = ui->name->text();
    QString passWord = ui->passWord->text();
    if (name.length() == 0 || passWord.length() == 0)
    {
        QMessageBox::critical(this, "错误", "用户名或密码为空！");
        return;
    }

    IDatabase& instance = IDatabase::GetInstance();

    QVector<QVariant> res = instance.findUser(name, passWord);

    if (res[0].toBool())
    {
        CurrLoginUserInfo *info = new CurrLoginUserInfo(res[1].toInt(), res[2].toString(), res[3].toInt());
        emit loginSuccess(info);
    }
    else
        QMessageBox::critical(this, "错误", "用户名或密码错误！");
}
