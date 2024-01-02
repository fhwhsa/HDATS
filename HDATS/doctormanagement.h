#ifndef DOCTORMANAGEMENT_H
#define DOCTORMANAGEMENT_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QItemSelectionModel>
#include <QString>


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

    void initView();
    void iniSignalSlots();

private slots:
    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);
    void do_btnFind();
    void do_btnAdd();
    void do_btnDelete();
    void do_btnModify();

// 这两个信号是由masterview接收，然后转向doctoredit处理
signals:
    void add();
    void modify(QSqlQueryModel *qm, int index);

};

#endif // DOCTORMANAGEMENT_H
