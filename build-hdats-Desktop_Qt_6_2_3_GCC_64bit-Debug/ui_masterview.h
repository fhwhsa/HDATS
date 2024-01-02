/********************************************************************************
** Form generated from reading UI file 'masterview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERVIEW_H
#define UI_MASTERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MasterView
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnReturn;
    QSpacerItem *horizontalSpacer;
    QLabel *currWidgetTitle;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnLoginout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *MasterView)
    {
        if (MasterView->objectName().isEmpty())
            MasterView->setObjectName(QString::fromUtf8("MasterView"));
        MasterView->resize(637, 409);
        verticalLayout_2 = new QVBoxLayout(MasterView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnReturn = new QPushButton(MasterView);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReturn->setIcon(icon);

        horizontalLayout->addWidget(btnReturn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        currWidgetTitle = new QLabel(MasterView);
        currWidgetTitle->setObjectName(QString::fromUtf8("currWidgetTitle"));

        horizontalLayout->addWidget(currWidgetTitle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnLoginout = new QPushButton(MasterView);
        btnLoginout->setObjectName(QString::fromUtf8("btnLoginout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/loginout.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoginout->setIcon(icon1);

        horizontalLayout->addWidget(btnLoginout);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(MasterView);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MasterView);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MasterView);
    } // setupUi

    void retranslateUi(QWidget *MasterView)
    {
        MasterView->setWindowTitle(QCoreApplication::translate("MasterView", "MasterView", nullptr));
        btnReturn->setText(QString());
        currWidgetTitle->setText(QString());
        btnLoginout->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MasterView: public Ui_MasterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERVIEW_H
