/********************************************************************************
** Form generated from reading UI file 'query.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_H
#define UI_QUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_query
{
public:
    QLineEdit *queryWord;
    QRadioButton *precise;
    QRadioButton *vague;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_2;
    QButtonGroup *precisionGroup;

    void setupUi(QWidget *query)
    {
        if (query->objectName().isEmpty())
            query->setObjectName(QStringLiteral("query"));
        query->resize(969, 685);
        queryWord = new QLineEdit(query);
        queryWord->setObjectName(QStringLiteral("queryWord"));
        queryWord->setGeometry(QRect(170, 30, 451, 51));
        precise = new QRadioButton(query);
        precisionGroup = new QButtonGroup(query);
        precisionGroup->setObjectName(QStringLiteral("precisionGroup"));
        precisionGroup->addButton(precise);
        precise->setObjectName(QStringLiteral("precise"));
        precise->setGeometry(QRect(360, 140, 151, 41));
        vague = new QRadioButton(query);
        precisionGroup->addButton(vague);
        vague->setObjectName(QStringLiteral("vague"));
        vague->setGeometry(QRect(520, 140, 151, 41));
        label = new QLabel(query);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 121, 51));
        tableWidget = new QTableWidget(query);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 220, 921, 441));
        pushButton = new QPushButton(query);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(700, 140, 171, 51));
        comboBox = new QComboBox(query);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 140, 141, 31));
        label_2 = new QLabel(query);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 140, 81, 18));

        retranslateUi(query);

        QMetaObject::connectSlotsByName(query);
    } // setupUi

    void retranslateUi(QWidget *query)
    {
        query->setWindowTitle(QApplication::translate("query", "Form", Q_NULLPTR));
        precise->setText(QApplication::translate("query", "\347\262\276\347\241\256\346\237\245\346\211\276", Q_NULLPTR));
        vague->setText(QApplication::translate("query", "\346\250\241\347\263\212\346\237\245\346\211\276", Q_NULLPTR));
        label->setText(QApplication::translate("query", "\346\237\245\350\257\242\345\205\263\351\224\256\345\255\227", Q_NULLPTR));
        pushButton->setText(QApplication::translate("query", "\346\220\234\347\264\242", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("query", "\346\214\211\345\225\206\345\223\201\345\220\215\347\247\260", Q_NULLPTR)
         << QApplication::translate("query", "\346\214\211\350\277\233\350\264\247/\345\207\272\350\264\247", Q_NULLPTR)
         << QApplication::translate("query", "\346\214\211\350\201\224\347\263\273\344\272\272", Q_NULLPTR)
         << QApplication::translate("query", "\346\214\211\344\272\247\345\234\260", Q_NULLPTR)
         << QApplication::translate("query", "\346\214\211\344\272\244\346\230\223\345\234\260\347\202\271", Q_NULLPTR)
         << QApplication::translate("query", "\346\214\211\344\272\244\346\230\223\345\215\225\344\275\215", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("query", "\346\237\245\350\257\242\347\261\273\345\210\253", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class query: public Ui_query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
