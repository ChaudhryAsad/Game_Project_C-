#include "game_screen.h"
#include "ui_game_screen.h"

#include "food.h"
#include "cherry.h"
#include "mango.h"
#include "muis.h"

#include <QPainter> ///The QPainter class performs low-level painting on widgets and other paint devices
#include <QApplication> ///The QApplication class manages the GUI application's control flow and main settings
#include <QThread> ///The QThread class provides a platform-independent way to manage threads

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

game_screen::game_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game_screen)
{
    ui->setupUi(this);
    x = 0;
    highscore = 0;
    score = 0;
    gameOver = false;
    paused = false;
    gameStarted = false;
    snake = new Snake(250, 350, 5); ///230 , 355 , 5
    food = new Cherry(2*40+27, 2*10+47);
    food = new Muis(2*40+27, 2*10+47);
    food = new Mango(2*40+27, 2*10+47); /* 32 : Dynamic memory allocation */
}
//----------------------------------
//hier worden snake en food gedelete
//----------------------------------
game_screen::~game_screen()
{
    delete ui;
    delete food;
    delete snake;/* 33 : Dynamic memory delete */
}
void game_screen::paintEvent(QPaintEvent *event) /* 56 : GUI 31: pointer (*)*/
{
    QPainter painter(this);/*15: this*/

    if (gameOver)
    {
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Game Over");
        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Game Over");

        if (newhigh == true)
        {
            int textWidth2 = fm.width("New High Score: ");
            int textWidth3 = fm.width(QString::number(highscore));

            painter.drawText(-textWidth2/2, 20, "New High Score: ");
            painter.drawText(-textWidth3/2, 40, QString::number(highscore));
        }
        else
        {
            int textWidth2 = fm.width("Last Score: ");
            int textWidth3 = fm.width(QString::number(score));

            painter.drawText(-textWidth2/2, 20, "Last Score: ");
            painter.drawText(-textWidth3/2, 40, QString::number(score));

            int textWidth4 = fm.width("High Score: ");
            int textWidth5 = fm.width(QString::number(highscore));

            painter.drawText(-textWidth4/2, 60, "High Score: ");
            painter.drawText(-textWidth5/2, 80, QString::number(highscore));
        }
    }
    else
    {
        QFont font("Courier", 10, QFont::DemiBold);
        int w = width();
//--------------------------------------------------------------------------
//Score word geteld telken wanneer snake fruit eet.
//Oude score blijft zo kan je zien hoeveel je vorige spel had.
//Er wordt telkens new fruit aan gemaakt
//--------------------------------------------------------------------------
        painter.setFont(font);
        painter.drawText(QPoint(w/-110, 10), "Old score: " + QString::number(highscore));
        painter.drawText(QPoint(w/2, 10), "Score: " + QString::number(score));
        painter.drawImage(food->getRect(), food->getImage());

        Snake::SegmentIterator iter;
        for (iter = snake->segments.begin(); iter != snake->segments.end(); ++iter)
        {
            painter.drawImage(iter->rect , iter->image);
        }
    }
}


void game_screen::timerEvent(QTimerEvent *event)
{
    snake->move();
    checkCollision();
    QThread::msleep(40);
    repaint();
}

//--------------------------------------------------------------------------
//Volgende toetsen worden voor het spel gebruikt.
//Je kunt gewoon de pijlen van toesten bord gebruiken
//--------------------------------------------------------------------------

void game_screen::keyPressEvent(QKeyEvent *event)/*59: project that works with hardware */
/// Keybord is used as harware
{
    switch (event->key()) {
    case Qt::Key_Left:///Key_Q:
         snake->dir = Snake::LEFT;
       break;
    case Qt::Key_Right: ///Key_D:
          snake->dir = Snake::RIGHT;
        break;
    case Qt::Key_Up: ///Key_Z:
          snake->dir = Snake::UP;
        break;
    case Qt::Key_Down: ///Key_S:
          snake->dir = Snake::DOWN;
        break;
    case Qt::Key_P:
          pauseGame();
        break;
    case Qt::Key_Space:
          startGame();
        break;
    case Qt::Key_Escape:
          qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
    repaint();
}

//--------------------------------------------------------------------------
//Wanner het spel start wordt er altijd niuew snake aan gemaakt,
//op vaste waarde.
//De score gaat terug op nul op het begin van het spel
//--------------------------------------------------------------------------
void game_screen::startGame()
{
    if (!gameStarted) {
        snake = new Snake(230, 355, 5);
        gameOver = false;
        score = 0;
        newhigh = false;
        gameStarted = true;
        timerId = startTimer(5);
    }
}

void game_screen::pauseGame()
{
    if (paused)
    {
        timerId = startTimer(5);
        paused = false;
    } else
    {
        paused = true;
        killTimer(timerId);
    }
}

void game_screen::stopGame()
{
    delete snake;
    killTimer(timerId);
    gameOver = true;
    if (score > highscore)
    {
        highscore = score;
        newhigh = true;
    }
    gameStarted = false;
}

//--------------------------------------------------------------------------
// food,muis en mango worden verschillende plaatsen gegeneert
// Als de snake food raakt wordt het destoryed
//Er word een limit in gesteld zodat snake niet groter word als de kader
//--------------------------------------------------------------------------

void game_screen::checkCollision()
{

    if (snake->head().rect.bottom() >= 500 || /* 53 : Testing */
       snake->head().rect.top() <= 0 ||
       snake->head().rect.left() <= 0 ||
       snake->head().rect.right() >= 300)
       stopGame();

    if ((snake->head().rect).intersects(food->getRect()))
    {
        food->setDestroyed(true);
        score += food->eaten(score); /* 10 : Polymorphism */
        delete food;


        switch (rand()%3)

        {


        case 0:
            food = new Cherry((1+(rand()%6))*40+27, (1+(rand()%30))*10+47);
            break;

        case 1:// komt minst vaak voor
            food = new Muis((1+(rand()%1))*40+27, (1+(rand()%10))*10+47);
             break;

        case 2:
            food = new Mango((1+(rand()%3))*40+27, (1+(rand()%30))*10+47);
             break;



        }
//--------------------------------------------------------------------------
// snake gaat telken met 1 vierkantje groter worden als hij iets eet
//--------------------------------------------------------------------------
        snake->growBy(1);
    }
//--------------------------------------------------------------------------
// Hier door kan snake niet tegenover richting draaien
//Als hij dat doet stopt het spel(gameover)
//--------------------------------------------------------------------------
    Snake::SegmentIterator iter; /* 53 : Testing */
    for (iter = ++snake->segments.begin(); iter != snake->segments.end(); ++iter)
        if (iter->x == snake->head().x && iter->y == snake->head().y)
            stopGame();
}

