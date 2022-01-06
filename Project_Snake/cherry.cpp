#include "cherry.h"

Cherry::Cherry(int x, int y) : Food(x,y) /* 17 : default values in function definition */
{
    image.load(":/images/food.png");
    rect = image.rect();
    rect.translate(x, y);
}

int Cherry::eaten(int oldScore)

{
    return 1;
}
