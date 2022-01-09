#include "muis.h"

Muis::Muis(int x , int y) : Food(x,y)
{
    image.load(":/images/mouse.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Muis::eaten(int oldScore)
{
    return 4;//bonus
}
