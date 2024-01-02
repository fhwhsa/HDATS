/********************************************************************************
** Form generated from reading UI file 'patientmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMANAGEMENT_H
#define UI_PATIENTMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientManagement
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnFind;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QPushButton *btnModify;
    QTableView *tableView;

    void setupUi(QWidget *PatientManagement)
    {
        if (PatientManagement->objectName().isEmpty())
            PatientManagement->setObjectName(QString::fromUtf8("PatientManagement"));
        PatientManagement->resize(683, 435);
        verticalLayout_2 = new QVBoxLayout(PatientManagement);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(PatientManagement);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnFind = new QPushButton(PatientManagement);
        btnFind->setObjectName(QString::fromUtf8("btnFind"));
        btnFind->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnFind);

        btnAdd = new QPushButton(PatientManagement);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnAdd);

        btnDelete = new QPushButton(PatientManagement);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnDelete);

        btnModify = new QPushButton(PatientManagement);
        btnModify->setObjectName(QString::fromUtf8("btnModify"));
        btnModify->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnModify);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(PatientManagement);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PatientManagement);

        QMetaObject::connectSlotsByName(PatientManagement);
    } // setupUi

    void retranslateUi(QWidget *PatientManagement)
    {
        PatientManagement->setWindowTitle(QCoreApplication::translate("PatientManagement", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineEdit->setInputMask(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("PatientManagement", "\350\276\223\345\205\245\345\247\223\345\220\215\357\274\210\346\250\241\347\263\212\346\237\245\350\257\242\357\274\211", nullptr));
        btnFind->setText(QCoreApplication::translate("PatientManagement", "\346\237\245\346\211\276", nullptr));
        btnAdd->setText(QCoreApplication::translate("PatientManagement", "\346\267\273\345\212\240", nullptr));
        btnDelete->setText(QCoreApplication::translate("PatientManagement", "\345\210\240\351\231\244", nullptr));
        btnModify->setText(QCoreApplication::translate("PatientManagement", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientManagement: public Ui_PatientManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMANAGEMENT_H
