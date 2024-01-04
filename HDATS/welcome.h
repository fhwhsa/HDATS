#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QVariant>
#include <QVector>

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QVector<QVariant> info, QWidget *parent = nullptr);
    ~Welcome();

    int getCurrLoginUserID();
    QString getCurrLoginUserName();
    int getCurrLoginUserLevel();

private:
    Ui::Welcome *ui;

    int currLoginUserID; // 当前登陆的用户的ID
    QString currLoginUserName;
    int currLoginUserLevel; // 权限等级

    void init();
    void iniSignalSlots();

signals:
    void diagRecords();
    void drugM();
    void departmentM();
    void doctorM();
    void patientM();
};

#endif // WELCOME_H
