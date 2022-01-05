#include "game.h"

#include <QPainter> ///The QPainter class performs low-level painting on widgets and other paint devices
#include <QApplication> ///The QApplication class manages the GUI application's control flow and main settings
#include <QThread> ///The QThread class provides a platform-independent way to manage threads

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

Game::Game(QWidget *parent) : /*QDesktopWidget*/QWidget(parent)
{
    x = 0;
    score = 0;
    highscore = 0;
    gameOver = false;
    paused = false;
    gameStarted = false;
    snake = new Snake(250, 350, 5); ///230 , 355 , 5

}
