/********************************************************************************
** Form generated from reading UI file 'game_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_SCREEN_H
#define UI_GAME_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_game_screen
{
public:

    void setupUi(QDialog *game_screen)
    {
        if (game_screen->objectName().isEmpty())
            game_screen->setObjectName(QString::fromUtf8("game_screen"));
        game_screen->resize(359, 528);

        retranslateUi(game_screen);

        QMetaObject::connectSlotsByName(game_screen);
    } // setupUi

    void retranslateUi(QDialog *game_screen)
    {
        game_screen->setWindowTitle(QCoreApplication::translate("game_screen", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_screen: public Ui_game_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_SCREEN_H
