#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; } /* 2: useful class*/
QT_END_NAMESPACE

class Game : public QMainWindow /* 3 : Useful encapsulation */
{
    Q_OBJECT
public:
  Game(QWidget *parent = nullptr); /* 16 : useful member function , 46 : NULLPTR */
  ~Game(); /* 14 : Destructor */


private:
    Ui::Game *ui;

protected:
  void paintEvent(QPaintEvent *event);
  void timerEvent(QTimerEvent *event); /* 49 : useful usage of signals/slots , timer = function from a class this is called everywhere */
  void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
