/********************************************************************************
** Form generated from reading UI file 'diagnosticrecords.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSTICRECORDS_H
#define UI_DIAGNOSTICRECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiagnosticRecords
{
public:

    void setupUi(QWidget *DiagnosticRecords)
    {
        if (DiagnosticRecords->objectName().isEmpty())
            DiagnosticRecords->setObjectName(QString::fromUtf8("DiagnosticRecords"));
        DiagnosticRecords->resize(400, 300);

        retranslateUi(DiagnosticRecords);

        QMetaObject::connectSlotsByName(DiagnosticRecords);
    } // setupUi

    void retranslateUi(QWidget *DiagnosticRecords)
    {
        DiagnosticRecords->setWindowTitle(QCoreApplication::translate("DiagnosticRecords", "\345\260\261\350\257\212\350\256\260\345\275\225\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiagnosticRecords: public Ui_DiagnosticRecords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSTICRECORDS_H
