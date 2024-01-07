#ifndef WELCOME_H
#define WELCOME_H

#include "currloginuserinfo.h"

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
    explicit Welcome(CurrLoginUserInfo *info, QWidget *parent = nullptr);
    ~Welcome();

private:
    Ui::Welcome *ui;

    CurrLoginUserInfo *info;

    void init();
    void iniSignalSlots();

signals:
    void diagRecords(CurrLoginUserInfo *info);
    void drugM();
    void doctorM();
    void patientM();
    void workReportM(CurrLoginUserInfo *info);
};

#endif // WELCOME_H
