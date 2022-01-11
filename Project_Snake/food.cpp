#include "food.h"
#include <iostream>

Food::Food(int x, int y) : destroyed(false) /* 13 : Member Initalization */
///Stuff behind semicolon ,, The different food's are loaded in the game , check the Other Files.
{
    ;
}

Food::~Food()
{
    std::cout << ("Food deleten\n"); /* 36 : Container Class */
}

QRect Food::getRect()
{
    return rect;
}

void Food::setRect(QRect rct) /* 19 : Setters for member variables */

{
    rect = rct;
}

QImage & Food::getImage() /* 19 : Getter */
{
    return image;
}

bool Food::isDestroyed()
{
    return destroyed;
}

void Food::setDestroyed(bool destr)
{
    destroyed = destr;
}

Cherry::Cherry(int x, int y) : Food(x,y) /* 17 : default values in function definition */
{
    image.load(":/images/cherry.png");
    rect = image.rect();
    rect.translate(x, y);
}
/***************************************************************
*Een return value geeft hier de score aan hoeveel ze waard zijn
***************************************************************/
int Cherry::eaten(int oldScore)

{
    return 1;
}

Mango::Mango(int x, int y) : Food(x,y)
/// Class is used (copied) multiple times (mango image)
{
    image.load(":/images/mango.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Mango::eaten(int oldScore)

{
    return 2;
}

Muis::Muis(int x , int y) : Food(x,y)
{
    image.load(":/images/mouse.png");/* 47: useful usage of (modern) file-I/O*/
/// Input is used to get the image
    rect = image.rect();
    rect.translate(x, y);
}

int Muis::eaten(int oldScore)
{
    return 4;//bonus
}
