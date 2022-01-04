#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QWidget>

//QT_BEGIN_NAMESPACE
//namespace Ui { class Game; } // 2: useful class
//QT_END_NAMESPACE

class Game : public QWidget // 3 : Useful encapsulation
//encapsulation wordt gedefinieerd als het samenbinden van de gegevens en de functies die ze manipuleren.
{
    Q_OBJECT
public:
  Game(QWidget *parent = nullptr); // 16 : useful member function , 46 : NULLPTR
  // Nullptr is a prvalue of type std::nullptr_t
  ~Game(); // 14 : Destructor




protected:
  void paintEvent(QPaintEvent *event);
  void timerEvent(QTimerEvent *event); // 49 : useful usage of signals/slots , timer = function from a class this is called everywhere
//Signals and slots are used for communication between objects.
  void keyPressEvent(QKeyEvent *event);

  void startGame();
  void startGame(int);
  void pauseGame();
  void stopGame();
  void checkCollision();

private:
//    Ui::Game *ui;
    int x;
    int timerId;
    unsigned char score; /* 26 : Unsinged char */
    unsigned char highscore;
//    Food *food;
    Snake *snake;
    bool gameOver; /* 30 : 4 Usefull BOOL */
    bool gameStarted;
    bool paused;
    bool newhigh;
};
#endif // MAINWINDOW_H
