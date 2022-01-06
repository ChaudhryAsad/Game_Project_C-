#ifndef CHERRY_H
#define CHERRY_H

#include "food.h" /* 25 : Seperated header file */
/*using namespace std; */

class Cherry : public Food /* 6 : Inheritance , 23 : Namespaces */
///Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application.
{
public:
    Cherry(); /* 11 : Defualt Constructor */
///Default constructor is the constructor which doesn’t take any argument.
///It has no parameters.

    Cherry(int, int); /* 12 : parameterized Constructor */
///Parameterized Constructor pass arguments to constructors. Typically, these arguments help initialize an object when it is created.

    int eaten(int oldScore);
};

#endif // CHERRY_H
