/********************************************************************************
** Form generated from reading UI file 'drugmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRUGMANAGEMENT_H
#define UI_DRUGMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrugManagement
{
public:

    void setupUi(QWidget *DrugManagement)
    {
        if (DrugManagement->objectName().isEmpty())
            DrugManagement->setObjectName(QString::fromUtf8("DrugManagement"));
        DrugManagement->resize(400, 300);

        retranslateUi(DrugManagement);

        QMetaObject::connectSlotsByName(DrugManagement);
    } // setupUi

    void retranslateUi(QWidget *DrugManagement)
    {
        DrugManagement->setWindowTitle(QCoreApplication::translate("DrugManagement", "\350\215\257\345\223\201\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrugManagement: public Ui_DrugManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRUGMANAGEMENT_H
