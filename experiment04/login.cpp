#include "login.h"
#include "ui_login.h"
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
    delete ui;
}

void Login::iniSignalSlots()
{
    connect(ui->btnLogin, SIGNAL(clicked()), this, SLOT(check()));
}

void Login::check()
{
    QString userName = ui->userName->text();
    QString passWord = ui->passWord->text();

    if (userName.length() == 0 || passWord.length() == 0)
    {
        QMessageBox::critical(this, "错误", "用户名或密码为空！");
        return;
    }

    if (true)
        emit loginSuccess();
    else
        emit loginFailed();
}