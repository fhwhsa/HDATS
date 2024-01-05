#ifndef DIAGNOSTICRECORD_H
#define DIAGNOSTICRECORD_H

#include "currloginuserinfo.h"

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
#include <QSortFilterProxyModel>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QSqlError>
#include <QTableView>

namespace Ui {
class DiagnosticRecord;
}

class DiagnosticRecord : public QWidget
{
    Q_OBJECT

public:
    explicit DiagnosticRecord(CurrLoginUserInfo *info, QWidget *parent = nullptr);
    ~DiagnosticRecord();

    void refresh();

private:
    Ui::DiagnosticRecord *ui;

    static QString drBaseSql;
    static QString mrBaseSql;

    CurrLoginUserInfo *info;

    QSqlQueryModel *drQueryModel; // 就诊记录
    QSqlQueryModel *mrQueryModel; // 药品开具记录
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

// 这两个信号是由masterview接收
signals:
    void add();
    void modify(QSortFilterProxyModel *sfpm, QModelIndex index);
};

#endif // DIAGNOSTICRECORD_H
