#ifndef DRUGMANAGEMENT_H
#define DRUGMANAGEMENT_H

#include <QWidget>
#include <QModelIndex>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
#include <QSortFilterProxyModel>
#include <QVector>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class DrugManagement;
}

class DrugManagement : public QWidget
{
    Q_OBJECT

public:
    explicit DrugManagement(QWidget *parent = nullptr);
    ~DrugManagement();

    void refresh();

private:
    Ui::DrugManagement *ui;

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

// 这两个信号是由masterview接收，然后转向druedit处理
signals:
    void add();
    void modify(QSortFilterProxyModel *sfpm, QModelIndex index);
};

#endif // DRUGMANAGEMENT_H
