/********************************************************************************
** Form generated from reading UI file 'modi_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODI_DIALOG_H
#define UI_MODI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modi_dialog
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *modi_dialog)
    {
        if (modi_dialog->objectName().isEmpty())
            modi_dialog->setObjectName(QStringLiteral("modi_dialog"));
        modi_dialog->resize(394, 198);
        lineEdit = new QLineEdit(modi_dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 30, 351, 71));
        pushButton = new QPushButton(modi_dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 130, 121, 51));
        pushButton_2 = new QPushButton(modi_dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 130, 121, 51));

        retranslateUi(modi_dialog);

        QMetaObject::connectSlotsByName(modi_dialog);
    } // setupUi

    void retranslateUi(QWidget *modi_dialog)
    {
        modi_dialog->setWindowTitle(QApplication::translate("modi_dialog", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("modi_dialog", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("modi_dialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modi_dialog: public Ui_modi_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODI_DIALOG_H
