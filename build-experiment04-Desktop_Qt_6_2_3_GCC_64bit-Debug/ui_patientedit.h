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
    QLineEdit *lineEdit_8;
    QLabel *label_14;
    QLineEdit *lineEdit_6;
    QLabel *label_13;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QComboBox *comboBox_2;
    QLabel *label_16;
    QDateEdit *dateEdit_2;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
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

        lineEdit_8 = new QLineEdit(PatientEdit);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy);
        lineEdit_8->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lineEdit_8, 0, 1, 1, 1);

        label_14 = new QLabel(PatientEdit);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(PatientEdit);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);
        lineEdit_6->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lineEdit_6, 1, 1, 1, 1);

        label_13 = new QLabel(PatientEdit);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(PatientEdit);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);
        lineEdit_5->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lineEdit_5, 2, 1, 1, 1);

        label_10 = new QLabel(PatientEdit);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 3, 0, 1, 1);

        comboBox_2 = new QComboBox(PatientEdit);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(comboBox_2, 3, 1, 1, 1);

        label_16 = new QLabel(PatientEdit);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 4, 0, 1, 1);

        dateEdit_2 = new QDateEdit(PatientEdit);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        sizePolicy.setHeightForWidth(dateEdit_2->sizePolicy().hasHeightForWidth());
        dateEdit_2->setSizePolicy(sizePolicy);
        dateEdit_2->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(dateEdit_2, 4, 1, 1, 1);

        label_9 = new QLabel(PatientEdit);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(PatientEdit);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        sizePolicy.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy);
        doubleSpinBox_4->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(doubleSpinBox_4, 5, 1, 1, 1);

        label_11 = new QLabel(PatientEdit);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(PatientEdit);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        sizePolicy.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy);
        doubleSpinBox_3->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(doubleSpinBox_3, 6, 1, 1, 1);

        label_12 = new QLabel(PatientEdit);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 7, 0, 1, 1);

        lineEdit_7 = new QLineEdit(PatientEdit);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);
        lineEdit_7->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(lineEdit_7, 7, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(PatientEdit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(PatientEdit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


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
        comboBox_2->setItemText(0, QString());
        comboBox_2->setItemText(1, QCoreApplication::translate("PatientEdit", "\347\224\267", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("PatientEdit", "\345\245\263", nullptr));

        label_16->setText(QCoreApplication::translate("PatientEdit", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("PatientEdit", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("PatientEdit", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("PatientEdit", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("PatientEdit", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PatientEdit", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientEdit: public Ui_PatientEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDIT_H
