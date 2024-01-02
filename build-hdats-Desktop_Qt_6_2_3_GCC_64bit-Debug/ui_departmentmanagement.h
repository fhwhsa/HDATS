/********************************************************************************
** Form generated from reading UI file 'departmentmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTMANAGEMENT_H
#define UI_DEPARTMENTMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepartmentManagement
{
public:

    void setupUi(QWidget *DepartmentManagement)
    {
        if (DepartmentManagement->objectName().isEmpty())
            DepartmentManagement->setObjectName(QString::fromUtf8("DepartmentManagement"));
        DepartmentManagement->resize(400, 300);

        retranslateUi(DepartmentManagement);

        QMetaObject::connectSlotsByName(DepartmentManagement);
    } // setupUi

    void retranslateUi(QWidget *DepartmentManagement)
    {
        DepartmentManagement->setWindowTitle(QCoreApplication::translate("DepartmentManagement", "\351\203\250\351\227\250\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepartmentManagement: public Ui_DepartmentManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTMANAGEMENT_H
