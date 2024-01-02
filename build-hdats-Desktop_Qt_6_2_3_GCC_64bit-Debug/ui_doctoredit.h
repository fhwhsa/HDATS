/********************************************************************************
** Form generated from reading UI file 'doctoredit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTOREDIT_H
#define UI_DOCTOREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorEdit
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *name;
    QLineEdit *phoneNum;
    QLabel *label_3;
    QComboBox *pLevel;
    QLabel *label_2;
    QComboBox *gender;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *PCNO;
    QLabel *label;
    QDateEdit *birthDate;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DoctorEdit)
    {
        if (DoctorEdit->objectName().isEmpty())
            DoctorEdit->setObjectName(QString::fromUtf8("DoctorEdit"));
        DoctorEdit->resize(562, 322);
        verticalLayout_2 = new QVBoxLayout(DoctorEdit);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(DoctorEdit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        name = new QLineEdit(DoctorEdit);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        phoneNum = new QLineEdit(DoctorEdit);
        phoneNum->setObjectName(QString::fromUtf8("phoneNum"));

        gridLayout->addWidget(phoneNum, 1, 1, 1, 1);

        label_3 = new QLabel(DoctorEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        pLevel = new QComboBox(DoctorEdit);
        pLevel->addItem(QString());
        pLevel->addItem(QString());
        pLevel->setObjectName(QString::fromUtf8("pLevel"));

        gridLayout->addWidget(pLevel, 4, 1, 1, 1);

        label_2 = new QLabel(DoctorEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        gender = new QComboBox(DoctorEdit);
        gender->addItem(QString());
        gender->addItem(QString());
        gender->setObjectName(QString::fromUtf8("gender"));

        gridLayout->addWidget(gender, 2, 1, 1, 1);

        label_4 = new QLabel(DoctorEdit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(DoctorEdit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        PCNO = new QLineEdit(DoctorEdit);
        PCNO->setObjectName(QString::fromUtf8("PCNO"));

        gridLayout->addWidget(PCNO, 5, 1, 1, 1);

        label = new QLabel(DoctorEdit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        birthDate = new QDateEdit(DoctorEdit);
        birthDate->setObjectName(QString::fromUtf8("birthDate"));

        gridLayout->addWidget(birthDate, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnSave = new QPushButton(DoctorEdit);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(DoctorEdit);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        verticalLayout->addWidget(btnCancel);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DoctorEdit);

        QMetaObject::connectSlotsByName(DoctorEdit);
    } // setupUi

    void retranslateUi(QWidget *DoctorEdit)
    {
        DoctorEdit->setWindowTitle(QCoreApplication::translate("DoctorEdit", "\347\274\226\350\276\221\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("DoctorEdit", "\346\235\203\351\231\220\347\255\211\347\272\247\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("DoctorEdit", "\346\200\247\345\210\253\357\274\232", nullptr));
        pLevel->setItemText(0, QCoreApplication::translate("DoctorEdit", "1", nullptr));
        pLevel->setItemText(1, QCoreApplication::translate("DoctorEdit", "2", nullptr));

        label_2->setText(QCoreApplication::translate("DoctorEdit", "\347\224\265\350\257\235\345\217\267\347\240\201\357\274\232", nullptr));
        gender->setItemText(0, QCoreApplication::translate("DoctorEdit", "\347\224\267", nullptr));
        gender->setItemText(1, QCoreApplication::translate("DoctorEdit", "\345\245\263", nullptr));

        label_4->setText(QCoreApplication::translate("DoctorEdit", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("DoctorEdit", "\346\211\247\344\270\232\350\257\201\344\271\246\345\217\267\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("DoctorEdit", "\345\247\223\345\220\215\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("DoctorEdit", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("DoctorEdit", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorEdit: public Ui_DoctorEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOREDIT_H
