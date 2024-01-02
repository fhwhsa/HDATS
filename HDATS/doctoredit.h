#ifndef DOCTOREDIT_H
#define DOCTOREDIT_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>
#include <QDate>
#include <QSqlRecord>
#include <QSqlError>

namespace Ui {
class DoctorEdit;
}

class DoctorEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorEdit(QSqlQueryModel *qm, int f = -1, QWidget *parent = nullptr);
    ~DoctorEdit();

private:
    Ui::DoctorEdit *ui;
    QSqlQueryModel *queryModel;

    static QString insertPrepare;
    static QString updatePrepare;
    static QString initPassWord; // 添加医生的初始密码

    int modifyIndex; // 标识该窗口是用于修改数据还是添加（-1为添加，其余为修改，并表示修改的行）

    void initData();
    void iniSignalSlots();

private slots:
    void do_btnSave();
    void do_btnCancel();

signals:
    void clickBtnCancel();
    void clickBtnSave();
};

#endif // DOCTOREDIT_H
