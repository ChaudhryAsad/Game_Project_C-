#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "snake.h"
#include "food.h"

#include <QDialog>
#include <QMainWindow>
#include <QKeyEvent>
#include <QWidget>
#include <QPaintEvent>


namespace Ui {
class game_screen;
}

class game_screen : public QDialog // 2: usefull calss 3 : Useful encapsulation
///encapsulation wordt gedefinieerd als het samenbinden van de gegevens en de functies die ze manipuleren.
{
    Q_OBJECT

public:
    explicit game_screen(QWidget *parent = nullptr);// 16 : useful member function , 46 : NULLPTR
/// Nullptr is a prvalue of type std::nullptr_t
    ~game_screen();// 14 : Destructor
///A destructor is a member function that is invoked automatically when the object goes out of scope or is explicitly destroyed by a call to delete


protected:
  void paintEvent(QPaintEvent *event);
  void timerEvent(QTimerEvent *event); // 49 : useful usage of signals/slots , timer = function from a class this is called everywhere
///Signals and slots are used for communication between objects.

  void keyPressEvent(QKeyEvent *event);

  void startGame();
  void startGame(int);
  void pauseGame();
  void stopGame();
  void checkCollision();


private:
    Ui::game_screen *ui;
    int x;
    int timerId;
    unsigned char score; /* 26 : Unsinged char */
    unsigned char highscore;
    Food *food; // door cherry.h kan deze gelezen worden
    Snake *snake;
    bool gameOver; /* 30 : 4 Usefull BOOL */
    bool gameStarted;
    bool paused;
    bool newhigh;
};

#endif // GAME_SCREEN_H
