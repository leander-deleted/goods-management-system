/********************************************************************************
** Form generated from reading UI file 'maingui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGUI_H
#define UI_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainGui
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *mainGui)
    {
        if (mainGui->objectName().isEmpty())
            mainGui->setObjectName(QStringLiteral("mainGui"));
        mainGui->resize(800, 483);
        label = new QLabel(mainGui);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 70, 331, 111));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        pushButton = new QPushButton(mainGui);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 290, 191, 101));
        pushButton_3 = new QPushButton(mainGui);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 290, 191, 101));
        pushButton_4 = new QPushButton(mainGui);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(530, 290, 191, 101));

        retranslateUi(mainGui);

        QMetaObject::connectSlotsByName(mainGui);
    } // setupUi

    void retranslateUi(QWidget *mainGui)
    {
        mainGui->setWindowTitle(QApplication::translate("mainGui", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("mainGui", "\347\211\251\350\265\204\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mainGui", "\345\275\225\345\205\245\345\222\214\347\274\226\350\276\221", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("mainGui", "\346\211\223\345\215\260\351\242\204\350\247\210", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("mainGui", "\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainGui: public Ui_mainGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGUI_H
