/********************************************************************************
** Form generated from reading UI file 'patientedit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTEDIT_H
#define UI_PATIENTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientEdit
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *name;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_14;
    QLabel *label_11;
    QDoubleSpinBox *height;
    QLabel *label_12;
    QComboBox *gender;
    QLabel *label_16;
    QDoubleSpinBox *weight;
    QLineEdit *phoneNum;
    QDateEdit *birthDate;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *PatientEdit)
    {
        if (PatientEdit->objectName().isEmpty())
            PatientEdit->setObjectName(QString::fromUtf8("PatientEdit"));
        PatientEdit->resize(504, 267);
        horizontalLayout_2 = new QHBoxLayout(PatientEdit);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        name = new QLineEdit(PatientEdit);
        name->setObjectName(QString::fromUtf8("name"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        label_10 = new QLabel(PatientEdit);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setKerning(true);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_9 = new QLabel(PatientEdit);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        label_14 = new QLabel(PatientEdit);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 0, 0, 1, 1);

        label_11 = new QLabel(PatientEdit);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 4, 0, 1, 1);

        height = new QDoubleSpinBox(PatientEdit);
        height->setObjectName(QString::fromUtf8("height"));
        sizePolicy.setHeightForWidth(height->sizePolicy().hasHeightForWidth());
        height->setSizePolicy(sizePolicy);
        height->setMinimumSize(QSize(200, 0));
        height->setMaximum(999.000000000000000);
        height->setSingleStep(1.000000000000000);

        gridLayout->addWidget(height, 3, 1, 1, 1);

        label_12 = new QLabel(PatientEdit);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 5, 0, 1, 1);

        gender = new QComboBox(PatientEdit);
        gender->addItem(QString());
        gender->addItem(QString());
        gender->setObjectName(QString::fromUtf8("gender"));
        sizePolicy.setHeightForWidth(gender->sizePolicy().hasHeightForWidth());
        gender->setSizePolicy(sizePolicy);
        gender->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(gender, 1, 1, 1, 1);

        label_16 = new QLabel(PatientEdit);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 2, 0, 1, 1);

        weight = new QDoubleSpinBox(PatientEdit);
        weight->setObjectName(QString::fromUtf8("weight"));
        sizePolicy.setHeightForWidth(weight->sizePolicy().hasHeightForWidth());
        weight->setSizePolicy(sizePolicy);
        weight->setMinimumSize(QSize(200, 0));
        weight->setMaximum(999.990000000000009);
        weight->setSingleStep(1.000000000000000);

        gridLayout->addWidget(weight, 4, 1, 1, 1);

        phoneNum = new QLineEdit(PatientEdit);
        phoneNum->setObjectName(QString::fromUtf8("phoneNum"));
        sizePolicy.setHeightForWidth(phoneNum->sizePolicy().hasHeightForWidth());
        phoneNum->setSizePolicy(sizePolicy);
        phoneNum->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(phoneNum, 5, 1, 1, 1);

        birthDate = new QDateEdit(PatientEdit);
        birthDate->setObjectName(QString::fromUtf8("birthDate"));

        gridLayout->addWidget(birthDate, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnSave = new QPushButton(PatientEdit);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(PatientEdit);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        verticalLayout->addWidget(btnCancel);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(PatientEdit);

        QMetaObject::connectSlotsByName(PatientEdit);
    } // setupUi

    void retranslateUi(QWidget *PatientEdit)
    {
        PatientEdit->setWindowTitle(QCoreApplication::translate("PatientEdit", "\347\274\226\350\276\221\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        label_10->setText(QCoreApplication::translate("PatientEdit", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("PatientEdit", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("PatientEdit", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("PatientEdit", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("PatientEdit", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        gender->setItemText(0, QCoreApplication::translate("PatientEdit", "\347\224\267", nullptr));
        gender->setItemText(1, QCoreApplication::translate("PatientEdit", "\345\245\263", nullptr));

        label_16->setText(QCoreApplication::translate("PatientEdit", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("PatientEdit", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("PatientEdit", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientEdit: public Ui_PatientEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDIT_H
