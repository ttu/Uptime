/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed Jan 27 17:17:02 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *lblDays;
    QLabel *lblHours;
    QLabel *lblMinutes;
    QLabel *lblSeconds;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(227, 31);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        lblDays = new QLabel(Widget);
        lblDays->setObjectName(QString::fromUtf8("lblDays"));
        lblDays->setGeometry(QRect(77, 9, 16, 16));
        QFont font;
        font.setPointSize(12);
        lblDays->setFont(font);
        lblHours = new QLabel(Widget);
        lblHours->setObjectName(QString::fromUtf8("lblHours"));
        lblHours->setGeometry(QRect(122, 9, 16, 16));
        lblHours->setFont(font);
        lblMinutes = new QLabel(Widget);
        lblMinutes->setObjectName(QString::fromUtf8("lblMinutes"));
        lblMinutes->setGeometry(QRect(167, 9, 16, 16));
        lblMinutes->setFont(font);
        lblSeconds = new QLabel(Widget);
        lblSeconds->setObjectName(QString::fromUtf8("lblSeconds"));
        lblSeconds->setGeometry(QRect(212, 9, 16, 16));
        lblSeconds->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(35, 0, 41, 31));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label->setLayoutDirection(Qt::RightToLeft);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 0, 31, 31));
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(135, 0, 31, 31));
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::RightToLeft);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 0, 31, 31));
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::RightToLeft);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(2, 5, 31, 21));
        label_5->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Uptime", 0, QApplication::UnicodeUTF8));
        lblDays->setText(QApplication::translate("Widget", "D", 0, QApplication::UnicodeUTF8));
        lblHours->setText(QApplication::translate("Widget", "H", 0, QApplication::UnicodeUTF8));
        lblMinutes->setText(QApplication::translate("Widget", "M", 0, QApplication::UnicodeUTF8));
        lblSeconds->setText(QApplication::translate("Widget", "S", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "222", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "22", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "22", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "22", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "UP", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
