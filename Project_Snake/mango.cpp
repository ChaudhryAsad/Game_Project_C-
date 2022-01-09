#include "mango.h"

Mango::Mango(int x, int y) : Food(x,y)
{
    image.load(":/images/mango.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Mango::eaten(int oldScore)

{
    return 2;
}
