#include "mango.h"

Mango::Mango(int x, int y) : Food(x,y)/*41: useful template function or class */
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
