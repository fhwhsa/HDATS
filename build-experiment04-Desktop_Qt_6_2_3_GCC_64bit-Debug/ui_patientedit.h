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
    QLabel *label_15;
    QLineEdit *id;
    QLabel *label_14;
    QLineEdit *name;
    QLabel *label_13;
    QLineEdit *idCard;
    QLabel *label_10;
    QComboBox *gender;
    QLabel *label_16;
    QDateEdit *dateOfBirth;
    QLabel *label_9;
    QDoubleSpinBox *height;
    QLabel *label_11;
    QDoubleSpinBox *weight;
    QLabel *label_12;
    QLineEdit *phoneNum;
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
        label_15 = new QLabel(PatientEdit);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QFont font;
        font.setKerning(true);
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_15, 0, 0, 1, 1);

        id = new QLineEdit(PatientEdit);
        id->setObjectName(QString::fromUtf8("id"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy);
        id->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(id, 0, 1, 1, 1);

        label_14 = new QLabel(PatientEdit);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        name = new QLineEdit(PatientEdit);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(name, 1, 1, 1, 1);

        label_13 = new QLabel(PatientEdit);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        idCard = new QLineEdit(PatientEdit);
        idCard->setObjectName(QString::fromUtf8("idCard"));
        sizePolicy.setHeightForWidth(idCard->sizePolicy().hasHeightForWidth());
        idCard->setSizePolicy(sizePolicy);
        idCard->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(idCard, 2, 1, 1, 1);

        label_10 = new QLabel(PatientEdit);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 3, 0, 1, 1);

        gender = new QComboBox(PatientEdit);
        gender->addItem(QString());
        gender->addItem(QString());
        gender->addItem(QString());
        gender->setObjectName(QString::fromUtf8("gender"));
        sizePolicy.setHeightForWidth(gender->sizePolicy().hasHeightForWidth());
        gender->setSizePolicy(sizePolicy);
        gender->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(gender, 3, 1, 1, 1);

        label_16 = new QLabel(PatientEdit);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 4, 0, 1, 1);

        dateOfBirth = new QDateEdit(PatientEdit);
        dateOfBirth->setObjectName(QString::fromUtf8("dateOfBirth"));
        sizePolicy.setHeightForWidth(dateOfBirth->sizePolicy().hasHeightForWidth());
        dateOfBirth->setSizePolicy(sizePolicy);
        dateOfBirth->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(dateOfBirth, 4, 1, 1, 1);

        label_9 = new QLabel(PatientEdit);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        height = new QDoubleSpinBox(PatientEdit);
        height->setObjectName(QString::fromUtf8("height"));
        sizePolicy.setHeightForWidth(height->sizePolicy().hasHeightForWidth());
        height->setSizePolicy(sizePolicy);
        height->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(height, 5, 1, 1, 1);

        label_11 = new QLabel(PatientEdit);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        weight = new QDoubleSpinBox(PatientEdit);
        weight->setObjectName(QString::fromUtf8("weight"));
        sizePolicy.setHeightForWidth(weight->sizePolicy().hasHeightForWidth());
        weight->setSizePolicy(sizePolicy);
        weight->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(weight, 6, 1, 1, 1);

        label_12 = new QLabel(PatientEdit);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 7, 0, 1, 1);

        phoneNum = new QLineEdit(PatientEdit);
        phoneNum->setObjectName(QString::fromUtf8("phoneNum"));
        sizePolicy.setHeightForWidth(phoneNum->sizePolicy().hasHeightForWidth());
        phoneNum->setSizePolicy(sizePolicy);
        phoneNum->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(phoneNum, 7, 1, 1, 1);


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
        label_15->setText(QCoreApplication::translate("PatientEdit", "ID\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("PatientEdit", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("PatientEdit", "\350\272\253\344\273\275\350\257\201\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("PatientEdit", "\346\200\247\345\210\253\357\274\232", nullptr));
        gender->setItemText(0, QString());
        gender->setItemText(1, QCoreApplication::translate("PatientEdit", "\347\224\267", nullptr));
        gender->setItemText(2, QCoreApplication::translate("PatientEdit", "\345\245\263", nullptr));

        label_16->setText(QCoreApplication::translate("PatientEdit", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("PatientEdit", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("PatientEdit", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("PatientEdit", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("PatientEdit", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("PatientEdit", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientEdit: public Ui_PatientEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDIT_H
