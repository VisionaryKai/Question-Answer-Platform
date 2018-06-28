/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *openButton;
    QPushButton *sendButton;
    QLabel *label;
    QLabel *label_2;
    QProgressBar *clientProgressBar;
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QLabel *clientStatusLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        openButton = new QPushButton(Widget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(160, 230, 75, 23));
        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(280, 230, 75, 23));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 60, 54, 21));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 120, 54, 21));
        clientProgressBar = new QProgressBar(Widget);
        clientProgressBar->setObjectName(QStringLiteral("clientProgressBar"));
        clientProgressBar->setGeometry(QRect(160, 170, 118, 23));
        clientProgressBar->setValue(0);
        hostLineEdit = new QLineEdit(Widget);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(160, 60, 113, 20));
        portLineEdit = new QLineEdit(Widget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(160, 120, 113, 20));
        clientStatusLabel = new QLabel(Widget);
        clientStatusLabel->setObjectName(QStringLiteral("clientStatusLabel"));
        clientStatusLabel->setGeometry(QRect(90, 170, 54, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        openButton->setText(QApplication::translate("Widget", "openButton", 0));
        sendButton->setText(QApplication::translate("Widget", "sendButton", 0));
        label->setText(QApplication::translate("Widget", "\344\270\273\346\234\272", 0));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243", 0));
        clientStatusLabel->setText(QApplication::translate("Widget", "\347\212\266\346\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
