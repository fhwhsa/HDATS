#ifndef WORKREPORTMANAGEMENT_H
#define WORKREPORTMANAGEMENT_H

#include "currloginuserinfo.h"

#include <QWidget>
#include <QVector>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QDebug>
#include <QString>

namespace Ui {
class WorkReportManagement;
}

class WorkReportManagement : public QWidget
{
    Q_OBJECT

public:
    explicit WorkReportManagement(CurrLoginUserInfo *info, QWidget *parent = nullptr);
    ~WorkReportManagement();

    void refresh();

private:
    Ui::WorkReportManagement *ui;

    CurrLoginUserInfo *info;

    QSqlQueryModel *queryModel;
    QItemSelectionModel *selModel;
    QSortFilterProxyModel* filterModel;

    QVector<bool> flag; // 控制升降序

    void init();
    void iniSignalSlots();

private slots:
    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);
    void do_btnFind();
    void do_btnAdd();
    void do_btnDelete();
    void do_btnModify();
    void do_tableView_sort(int column);

// 这两个信号是由masterview接收，然后转向workreportedit处理
signals:
    void add(CurrLoginUserInfo *info);
    void modify(CurrLoginUserInfo *info, QSortFilterProxyModel *sfpm, QModelIndex index);
};

#endif // WORKREPORTMANAGEMENT_H
