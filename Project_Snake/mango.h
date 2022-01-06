#ifndef MANGO_H
#define MANGO_H
#include "food.h"

class Mango : public Food
{
public:
    Mango(); /* 11 : Default Constructor */
    Mango(int, int);

    int eaten(int oldScore);
};

#endif // MANGO_H
