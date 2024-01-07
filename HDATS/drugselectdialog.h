#ifndef DRUGSELECTDIALOG_H
#define DRUGSELECTDIALOG_H

#include "idatabase.h"

#include <QDialog>
#include <QDebug>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QItemSelectionModel>
#include <QString>

namespace Ui {
class DrugSelectDialog;
}

class DrugSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DrugSelectDialog(QWidget *parent = nullptr);
    ~DrugSelectDialog();

private:
    Ui::DrugSelectDialog *ui;

    QSqlQueryModel *queryModel;
    QItemSelectionModel *selModel;

    void init();
    void iniSignalSlots();

private slots:

    void do_btnFind();
    void do_btnRefreshDrugInfo();
    void do_btnCancel();
    void do_btnOk();
    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);

signals:

    void selected(QString name);

};

#endif // DRUGSELECTDIALOG_H
