/********************************************************************************
** Form generated from reading UI file 'doctormanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORMANAGEMENT_H
#define UI_DOCTORMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorManagement
{
public:

    void setupUi(QWidget *DoctorManagement)
    {
        if (DoctorManagement->objectName().isEmpty())
            DoctorManagement->setObjectName(QString::fromUtf8("DoctorManagement"));
        DoctorManagement->resize(400, 300);

        retranslateUi(DoctorManagement);

        QMetaObject::connectSlotsByName(DoctorManagement);
    } // setupUi

    void retranslateUi(QWidget *DoctorManagement)
    {
        DoctorManagement->setWindowTitle(QCoreApplication::translate("DoctorManagement", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorManagement: public Ui_DoctorManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORMANAGEMENT_H
