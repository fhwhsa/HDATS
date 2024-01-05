#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QVector>
#include <QVariant>

#include "currloginuserinfo.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    void iniSignalSlots();

private slots:
    void check();

signals:
    void loginSuccess(CurrLoginUserInfo* info);
    void loginFailed();

};

#endif // LOGIN_H
