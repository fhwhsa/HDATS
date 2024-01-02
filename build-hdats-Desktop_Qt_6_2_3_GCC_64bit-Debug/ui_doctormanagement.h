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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorManagement
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

    void setupUi(QWidget *DoctorManagement)
    {
        if (DoctorManagement->objectName().isEmpty())
            DoctorManagement->setObjectName(QString::fromUtf8("DoctorManagement"));
        DoctorManagement->resize(663, 402);
        verticalLayout_2 = new QVBoxLayout(DoctorManagement);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(DoctorManagement);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnFind = new QPushButton(DoctorManagement);
        btnFind->setObjectName(QString::fromUtf8("btnFind"));

        horizontalLayout->addWidget(btnFind);

        btnAdd = new QPushButton(DoctorManagement);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        horizontalLayout->addWidget(btnAdd);

        btnDelete = new QPushButton(DoctorManagement);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        horizontalLayout->addWidget(btnDelete);

        btnModify = new QPushButton(DoctorManagement);
        btnModify->setObjectName(QString::fromUtf8("btnModify"));

        horizontalLayout->addWidget(btnModify);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(DoctorManagement);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DoctorManagement);

        QMetaObject::connectSlotsByName(DoctorManagement);
    } // setupUi

    void retranslateUi(QWidget *DoctorManagement)
    {
        DoctorManagement->setWindowTitle(QCoreApplication::translate("DoctorManagement", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("DoctorManagement", "\350\276\223\345\205\245\345\247\223\345\220\215\357\274\210\346\250\241\347\263\212\346\237\245\350\257\242\357\274\211", nullptr));
        btnFind->setText(QCoreApplication::translate("DoctorManagement", "\346\237\245\346\211\276", nullptr));
        btnAdd->setText(QCoreApplication::translate("DoctorManagement", "\346\267\273\345\212\240", nullptr));
        btnDelete->setText(QCoreApplication::translate("DoctorManagement", "\345\210\240\351\231\244", nullptr));
        btnModify->setText(QCoreApplication::translate("DoctorManagement", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorManagement: public Ui_DoctorManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORMANAGEMENT_H
