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
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QVector>
#include <QVariant>

namespace Ui {
class DoctorEdit;
}

class DoctorEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorEdit(QString op, QWidget *parent = nullptr);
    explicit DoctorEdit(QSortFilterProxyModel *sfpm, QModelIndex i, QString op, QWidget *parent = nullptr);
    ~DoctorEdit();

private:
    Ui::DoctorEdit *ui;
    QSortFilterProxyModel *sfpm;

    static QString initPassWord; // 添加医生的初始密码
    QString operation; // 记录当前页面是用于添加还是修改

    QModelIndex index;

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
