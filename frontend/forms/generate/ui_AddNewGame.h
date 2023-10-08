/********************************************************************************
** Form generated from reading UI file 'AddNewGame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWGAME_H
#define UI_ADDNEWGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNewGame
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lable;
    QLineEdit *line_edit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_push_btn;
    QPushButton *cancel_push_btn;

    void setupUi(QDialog *AddNewGame)
    {
        if (AddNewGame->objectName().isEmpty())
            AddNewGame->setObjectName(QString::fromUtf8("AddNewGame"));
        AddNewGame->resize(459, 78);
        verticalLayout = new QVBoxLayout(AddNewGame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lable = new QLabel(AddNewGame);
        lable->setObjectName(QString::fromUtf8("lable"));

        horizontalLayout->addWidget(lable);

        line_edit = new QLineEdit(AddNewGame);
        line_edit->setObjectName(QString::fromUtf8("line_edit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        line_edit->setFont(font);

        horizontalLayout->addWidget(line_edit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ok_push_btn = new QPushButton(AddNewGame);
        ok_push_btn->setObjectName(QString::fromUtf8("ok_push_btn"));

        horizontalLayout_2->addWidget(ok_push_btn);

        cancel_push_btn = new QPushButton(AddNewGame);
        cancel_push_btn->setObjectName(QString::fromUtf8("cancel_push_btn"));

        horizontalLayout_2->addWidget(cancel_push_btn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddNewGame);

        QMetaObject::connectSlotsByName(AddNewGame);
    } // setupUi

    void retranslateUi(QDialog *AddNewGame)
    {
        AddNewGame->setWindowTitle(QApplication::translate("AddNewGame", "Dialog", nullptr));
#ifndef QT_NO_TOOLTIP
        lable->setToolTip(QApplication::translate("AddNewGame", "Settings name", nullptr));
#endif // QT_NO_TOOLTIP
        lable->setText(QApplication::translate("AddNewGame", "New game settings name:", nullptr));
#ifndef QT_NO_TOOLTIP
        line_edit->setToolTip(QApplication::translate("AddNewGame", "Settings name", nullptr));
#endif // QT_NO_TOOLTIP
        ok_push_btn->setText(QApplication::translate("AddNewGame", "Ok", nullptr));
        cancel_push_btn->setText(QApplication::translate("AddNewGame", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewGame: public Ui_AddNewGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWGAME_H
