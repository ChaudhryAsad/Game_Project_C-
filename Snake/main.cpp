#include <iostream>
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

}
void Logic()
{

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
