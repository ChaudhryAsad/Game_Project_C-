#ifndef FOOD_H
#define FOOD_H

#include <QImage> /* 37 : QT class*/
#include <QRect>

class Food /* 7 : Base class */
///A base class is a class in Object-Oriented Programming language, from which other classes are derived.
{

public:
Food(int, int); /* 11 : parameterized Constructor */
///Parameterized Constructor pass arguments to constructors. Typically, these arguments help initialize an object when it is created.

~Food(); /* 14 : Deconstructor */

  virtual int eaten(int oldScore) = 0; /* 9 : Virtual Function */
/// This makes is abstract Modifier that defines polymorphic behavior , using this to override in other classses.

public:
  void resetState();
  bool isDestroyed();
  void setDestroyed(bool); /* 16 : Member Function */
///is a function that has its definition or its prototype within the class definition like any other variable
///(function that is part of the class).

  QRect getRect();
  void setRect(QRect);
  QImage & getImage();

protected: /* 20 : Protection */
  QImage image; /* 18 : Member Variabel */
///A variable (an object) that is part of a class.
  QRect rect;

private:
  unsigned char points; /* 24 : Unsigned Char */
///the unsigned char will store 0 to 255
  bool destroyed;

};

#endif // FOOD_H
