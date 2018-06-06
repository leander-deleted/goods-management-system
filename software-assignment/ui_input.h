/********************************************************************************
** Form generated from reading UI file 'input.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_input
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *catogory;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *EI;
    QLabel *label_19;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_18;
    QLineEdit *lineEdit_9;
    QHBoxLayout *size;
    QLabel *label_17;
    QComboBox *comboBox_2;
    QHBoxLayout *place_2;
    QLabel *label_16;
    QLineEdit *lineEdit_8;
    QHBoxLayout *place;
    QLabel *label_15;
    QLineEdit *lineEdit_7;
    QHBoxLayout *number;
    QLabel *label_14;
    QLineEdit *lineEdit_6;
    QHBoxLayout *price;
    QLabel *label_13;
    QLineEdit *lineEdit_5;
    QHBoxLayout *apartmentAddr;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QHBoxLayout *contactName;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QHBoxLayout *contactTel;
    QLabel *label_11;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *input)
    {
        if (input->objectName().isEmpty())
            input->setObjectName(QStringLiteral("input"));
        input->resize(900, 741);
        pushButton = new QPushButton(input);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 470, 171, 71));
        QFont font;
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(input);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(630, 590, 171, 71));
        pushButton_2->setFont(font);
        layoutWidget = new QWidget(input);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 501, 621));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        catogory = new QHBoxLayout();
        catogory->setObjectName(QStringLiteral("catogory"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        catogory->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        catogory->addWidget(comboBox);


        verticalLayout->addLayout(catogory);

        EI = new QHBoxLayout();
        EI->setObjectName(QStringLiteral("EI"));
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        EI->addWidget(label_19);

        comboBox_3 = new QComboBox(layoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        EI->addWidget(comboBox_3);


        verticalLayout->addLayout(EI);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_10->addWidget(label_18);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        horizontalLayout_10->addWidget(lineEdit_9);


        verticalLayout->addLayout(horizontalLayout_10);

        size = new QHBoxLayout();
        size->setObjectName(QStringLiteral("size"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        size->addWidget(label_17);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        size->addWidget(comboBox_2);


        verticalLayout->addLayout(size);

        place_2 = new QHBoxLayout();
        place_2->setObjectName(QStringLiteral("place_2"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        place_2->addWidget(label_16);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        place_2->addWidget(lineEdit_8);


        verticalLayout->addLayout(place_2);

        place = new QHBoxLayout();
        place->setObjectName(QStringLiteral("place"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        place->addWidget(label_15);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        place->addWidget(lineEdit_7);


        verticalLayout->addLayout(place);

        number = new QHBoxLayout();
        number->setObjectName(QStringLiteral("number"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        number->addWidget(label_14);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        number->addWidget(lineEdit_6);


        verticalLayout->addLayout(number);

        price = new QHBoxLayout();
        price->setObjectName(QStringLiteral("price"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        price->addWidget(label_13);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        price->addWidget(lineEdit_5);


        verticalLayout->addLayout(price);

        apartmentAddr = new QHBoxLayout();
        apartmentAddr->setObjectName(QStringLiteral("apartmentAddr"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        apartmentAddr->addWidget(label_9);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        apartmentAddr->addWidget(lineEdit);


        verticalLayout->addLayout(apartmentAddr);

        contactName = new QHBoxLayout();
        contactName->setObjectName(QStringLiteral("contactName"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        contactName->addWidget(label_10);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        contactName->addWidget(lineEdit_2);


        verticalLayout->addLayout(contactName);

        contactTel = new QHBoxLayout();
        contactTel->setObjectName(QStringLiteral("contactTel"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        contactTel->addWidget(label_11);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        contactTel->addWidget(lineEdit_3);


        verticalLayout->addLayout(contactTel);

        layoutWidget->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(input);

        QMetaObject::connectSlotsByName(input);
    } // setupUi

    void retranslateUi(QWidget *input)
    {
        input->setWindowTitle(QApplication::translate("input", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("input", "\346\217\220\344\272\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("input", "\346\270\205\347\251\272", Q_NULLPTR));
        label->setText(QApplication::translate("input", "\347\247\215\347\261\273", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("input", "\351\207\221\345\261\236\346\235\220\346\226\231", Q_NULLPTR)
         << QApplication::translate("input", "\345\214\226\345\267\245\346\235\220\346\226\231", Q_NULLPTR)
         << QApplication::translate("input", "\346\234\272\347\224\265\344\272\224\351\207\221", Q_NULLPTR)
         << QApplication::translate("input", "\345\273\272\347\255\221\346\235\220\346\226\231", Q_NULLPTR)
         << QApplication::translate("input", "\350\275\246\350\276\206\351\205\215\344\273\266", Q_NULLPTR)
         << QApplication::translate("input", "\346\260\264\344\272\247\345\223\201", Q_NULLPTR)
         << QApplication::translate("input", "\346\210\277\345\234\260\344\272\247", Q_NULLPTR)
         << QApplication::translate("input", "\344\272\272\346\211\215\345\270\202\345\234\272", Q_NULLPTR)
         << QApplication::translate("input", "\345\205\266\344\273\226", Q_NULLPTR)
        );
        label_19->setText(QApplication::translate("input", "\350\277\233\350\264\247\345\207\272\350\264\247", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("input", "\350\277\233\350\264\247", Q_NULLPTR)
         << QApplication::translate("input", "\345\207\272\350\264\247", Q_NULLPTR)
        );
        label_18->setText(QApplication::translate("input", "\345\225\206\345\223\201\345\220\215\345\255\227", Q_NULLPTR));
        label_17->setText(QApplication::translate("input", "\345\244\247\345\260\217", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("input", "\345\244\247", Q_NULLPTR)
         << QApplication::translate("input", "\344\270\255", Q_NULLPTR)
         << QApplication::translate("input", "\345\260\217", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("input", "\344\272\247\345\234\260", Q_NULLPTR));
        label_15->setText(QApplication::translate("input", "\344\272\244\346\230\223\345\234\260\347\202\271", Q_NULLPTR));
        label_14->setText(QApplication::translate("input", "\346\225\260\351\207\217", Q_NULLPTR));
        label_13->setText(QApplication::translate("input", "\344\273\267\346\240\274", Q_NULLPTR));
        label_9->setText(QApplication::translate("input", "\344\272\244\346\230\223\345\215\225\344\275\215\345\234\260\345\235\200", Q_NULLPTR));
        label_10->setText(QApplication::translate("input", "\350\201\224\347\263\273\344\272\272\345\247\223\345\220\215", Q_NULLPTR));
        label_11->setText(QApplication::translate("input", "\350\201\224\347\263\273\344\272\272\347\224\265\350\257\235", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class input: public Ui_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
