#ifndef MUIS_H
#define MUIS_H

#include "food.h"

class Muis : public Food
{
public:
    Muis(); /* 11 : Default Constructor */
    Muis(int, int); /* 12 : Parameterized Constructor */

    int eaten(int oldScore);
};

#endif // MUIS_H
