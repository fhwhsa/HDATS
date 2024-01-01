#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(int qLevel, QWidget *parent = nullptr);
    ~Welcome();

private:
    Ui::Welcome *ui;
    int level; // 权限等级
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
