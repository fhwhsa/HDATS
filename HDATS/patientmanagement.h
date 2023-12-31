#ifndef PATIENTMANAGEMENT_H
#define PATIENTMANAGEMENT_H

#include <QWidget>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QSqlRecord>
#include <QItemDelegate>
#include <QAbstractItemView>
#include <QModelIndex>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSortFilterProxyModel>
#include <QVector>

namespace Ui {
class PatientManagement;
}

class PatientManagement : public QWidget
{
    Q_OBJECT

public:
    explicit PatientManagement(QWidget *parent = nullptr);
    ~PatientManagement();

    void refresh();

private:
    Ui::PatientManagement *ui;

    QSqlQueryModel *queryModel;
    QItemSelectionModel *selModel;
    QSortFilterProxyModel *filterModel;

    QVector<bool> flag;

    void iniSignalSlots();
    void initView();

private slots:
    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);
    void do_btnFind();
    void do_btnAdd();
    void do_btnDelete();
    void do_btnModify();
    void do_tableView_sort(int column);


// 这两个信号是由masterview接收，然后转向patientedit处理
signals:
    void add();
    void modify(QSortFilterProxyModel *sfpm, QModelIndex index);
};

#endif // PATIENTMANAGEMENT_H
