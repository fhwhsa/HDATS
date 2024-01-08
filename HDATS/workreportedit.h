#ifndef WORKREPORTEDIT_H
#define WORKREPORTEDIT_H

#include "currloginuserinfo.h"
#include "idatabase.h"

#include <QWidget>
#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QVector>
#include <QVariant>

namespace Ui {
class WorkReportEdit;
}

class WorkReportEdit : public QWidget
{
    Q_OBJECT

public:
    explicit WorkReportEdit(CurrLoginUserInfo *info, QString op, QWidget *parent = nullptr);
    explicit WorkReportEdit(CurrLoginUserInfo *info, QSortFilterProxyModel *sfpm, QModelIndex index, QString op, QWidget *parent = nullptr);
    ~WorkReportEdit();

private:
    Ui::WorkReportEdit *ui;

    CurrLoginUserInfo *info;

    QSortFilterProxyModel *sfpm;
    QModelIndex index;

    QString operation;

    void init();
    void iniSignalSlots();

private slots:
    void do_btnSave();
    void do_btnCancel();

signals:
    void clickBtnCancel();
    void clickBtnSave();
};

#endif // WORKREPORTEDIT_H
