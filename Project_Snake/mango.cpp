#include "mango.h"

Mango::Mango(int x, int y) : Food(x,y)
{
    image.load(":/images/food2.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Mango::eaten(int oldScore)

{
    return 2;
}
