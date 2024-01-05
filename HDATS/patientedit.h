#ifndef PATIENTEDIT_H
#define PATIENTEDIT_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDate>
#include <QSqlError>
#include <QString>
#include <QMessageBox>
#include <QModelIndex>
#include <QSortFilterProxyModel>
#include <QVector>
#include <QVariant>

namespace Ui {
class PatientEdit;
}

class PatientEdit : public QWidget
{
    Q_OBJECT

public:
    explicit PatientEdit(QString op, QWidget *parent = nullptr);
    explicit PatientEdit(QSortFilterProxyModel *sfpm, QModelIndex i, QString op, QWidget *parent = nullptr);
    ~PatientEdit();

private:
    Ui::PatientEdit *ui;
    QSortFilterProxyModel *sfpm;

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

#endif // PATIENTEDIT_H
