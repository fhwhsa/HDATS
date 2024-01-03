#ifndef DRUGEDIT_H
#define DRUGEDIT_H

#include <QWidget>
#include <QString>
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>

namespace Ui {
class DrugEdit;
}

class DrugEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DrugEdit(QString op, QWidget *parent = nullptr);
    explicit DrugEdit(QSortFilterProxyModel *sfpm, QModelIndex i, QString op, QWidget *parent = nullptr);
    ~DrugEdit();

private:
    Ui::DrugEdit *ui;
    QSortFilterProxyModel *sfpm;

    static QString insertPrepare;
    static QString updatePrepare;
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

#endif // DRUGEDIT_H
