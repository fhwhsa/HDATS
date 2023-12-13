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

namespace Ui {
class PatientManagement;
}

class PatientManagement : public QWidget
{
    Q_OBJECT

public:
    explicit PatientManagement(QWidget *parent = nullptr);
    ~PatientManagement();

private:
    Ui::PatientManagement *ui;

    QSqlTableModel *tableModel;
    QItemSelectionModel *selModel;

    void iniSignalSlots();
    void initView();

private slots:
    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);
    void do_btnFind();
    void do_btnDelete();
    void do_btnModify();

signals:
    void add();
};

#endif // PATIENTMANAGEMENT_H
