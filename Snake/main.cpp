#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x,y, fruitX, fruitY, score; //Hoofd en fruit positie

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN}; // om positie te zien
eDirection dir;




void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2; //zodat snake kop gecenterd wordt
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;

}
void DrawWall()
{
    system("cls"); //system("clear");
    for (int i = 0; i < width +2; i++)// top van het bord
        cout << "#";
      cout << endl; //next line

      for(int i = 0; i < width; i++)
      {
          for(int j = 0; j < width; j++)
          {
            if (j==0)
               cout << "#"; // als j = 0 dan print hij # anders een spactie
            if (i == y && j == x)
               cout << "O"; //print hoofd

            else if (i == fruitY && j == fruitX)
               cout << "F"; // print Fruit
               cout << " ";

            if (j == width - 1)
                cout << "#";

          }
          cout << endl;
      }

    for (int i = 0; i < width +2; i++)
        cout << "#";
      cout << endl; //next line
}
void Input()
{
    if(_kbhit()) // boolean
    {
        switch (_getch()) // deze geeft gedrukte value terug
        {
        case 'q':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 'z':
            dir = UP;
            break;

        case 'w':
            dir = DOWN;
            break;

            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    switch (dir) {

    case STOP:
        break;
    case LEFT:
        break;
    case RIGHT:
        break;
    case UP:
        break;
    case DOWN:
        break;
    default:
        break;
    }
}
int main()
{
    Setup();
    while (!gameOver)
    {
        DrawWall();
        Input();
        Logic();
    }
    return 0;
}
