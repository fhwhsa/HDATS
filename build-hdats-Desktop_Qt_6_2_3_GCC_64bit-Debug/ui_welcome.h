/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnDrugManagement;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDepartmentManagement;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnDoctorManagement;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDiagnosticRecords;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnPatientManagement;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->resize(662, 423);
        verticalLayout_2 = new QVBoxLayout(Welcome);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        btnDrugManagement = new QPushButton(Welcome);
        btnDrugManagement->setObjectName(QString::fromUtf8("btnDrugManagement"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnDrugManagement->sizePolicy().hasHeightForWidth());
        btnDrugManagement->setSizePolicy(sizePolicy);
        btnDrugManagement->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(btnDrugManagement);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnDepartmentManagement = new QPushButton(Welcome);
        btnDepartmentManagement->setObjectName(QString::fromUtf8("btnDepartmentManagement"));
        sizePolicy.setHeightForWidth(btnDepartmentManagement->sizePolicy().hasHeightForWidth());
        btnDepartmentManagement->setSizePolicy(sizePolicy);
        btnDepartmentManagement->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(btnDepartmentManagement);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnDoctorManagement = new QPushButton(Welcome);
        btnDoctorManagement->setObjectName(QString::fromUtf8("btnDoctorManagement"));
        sizePolicy.setHeightForWidth(btnDoctorManagement->sizePolicy().hasHeightForWidth());
        btnDoctorManagement->setSizePolicy(sizePolicy);
        btnDoctorManagement->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(btnDoctorManagement);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btnDiagnosticRecords = new QPushButton(Welcome);
        btnDiagnosticRecords->setObjectName(QString::fromUtf8("btnDiagnosticRecords"));
        sizePolicy.setHeightForWidth(btnDiagnosticRecords->sizePolicy().hasHeightForWidth());
        btnDiagnosticRecords->setSizePolicy(sizePolicy);
        btnDiagnosticRecords->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(btnDiagnosticRecords);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnPatientManagement = new QPushButton(Welcome);
        btnPatientManagement->setObjectName(QString::fromUtf8("btnPatientManagement"));
        sizePolicy.setHeightForWidth(btnPatientManagement->sizePolicy().hasHeightForWidth());
        btnPatientManagement->setSizePolicy(sizePolicy);
        btnPatientManagement->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(btnPatientManagement);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QCoreApplication::translate("Welcome", "\346\254\242\350\277\216", nullptr));
        btnDrugManagement->setText(QCoreApplication::translate("Welcome", "\350\215\257\345\223\201\347\256\241\347\220\206", nullptr));
        btnDepartmentManagement->setText(QCoreApplication::translate("Welcome", "\351\203\250\351\227\250\347\256\241\347\220\206", nullptr));
        btnDoctorManagement->setText(QCoreApplication::translate("Welcome", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        btnDiagnosticRecords->setText(QCoreApplication::translate("Welcome", "\345\260\261\350\257\212\350\256\260\345\275\225", nullptr));
        btnPatientManagement->setText(QCoreApplication::translate("Welcome", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
