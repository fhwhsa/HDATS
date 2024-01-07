#ifndef PATIENTSELECTDIALOG_H
#define PATIENTSELECTDIALOG_H

#include "idatabase.h"

#include <QDialog>
#include <QDebug>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QItemSelectionModel>

namespace Ui {
class PatientSelectDialog;
}

class PatientSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientSelectDialog(QWidget *parent = nullptr);
    ~PatientSelectDialog();

private:
    Ui::PatientSelectDialog *ui;

    QSqlQueryModel *queryModel;
    QItemSelectionModel *selModel;

    void init();
    void iniSignalSlots();

private slots:
    void do_btnFind();
    void do_btnCancel();
    void do_btnOk();
    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);

signals:
    void selected(QString name);

};

#endif // PATIENTSELECTDIALOG_H
