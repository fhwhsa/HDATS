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

namespace Ui {
class PatientEdit;
}

class PatientEdit : public QWidget
{
    Q_OBJECT

public:
    explicit PatientEdit(QSqlQueryModel *qm, int f = -1, QWidget *parent = nullptr);
    ~PatientEdit();

private:
    Ui::PatientEdit *ui;
    QSqlQueryModel *queryModel;

    static QString insertPrepare;
    static QString updatePrepare;

    int modifyIndex; // 标识该窗口是用于修改数据还是添加（-1为添加，其余为修改，并表示修改的行）

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
