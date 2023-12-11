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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
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
        pushButton = new QPushButton(PatientManagement);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(PatientManagement);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(PatientManagement);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(PatientManagement);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(pushButton_3);


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
        pushButton->setText(QCoreApplication::translate("PatientManagement", "\346\237\245\346\211\276", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PatientManagement", "\346\267\273\345\212\240", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PatientManagement", "\345\210\240\351\231\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PatientManagement", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientManagement: public Ui_PatientManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMANAGEMENT_H
