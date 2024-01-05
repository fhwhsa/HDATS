#ifndef DOCTORMANAGEMENT_H
#define DOCTORMANAGEMENT_H

#include "idatabase.h"

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QItemSelectionModel>
#include <QString>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QVector>

namespace Ui {
class DoctorManagement;
}

class DoctorManagement : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorManagement(QWidget *parent = nullptr);
    ~DoctorManagement();

    void refresh();

private:
    Ui::DoctorManagement *ui;

    static QString baseSql;

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

// 这两个信号是由masterview接收，然后转向doctoredit处理
signals:
    void add();
    void modify(QSortFilterProxyModel *sfpm, QModelIndex index);

};

#endif // DOCTORMANAGEMENT_H
