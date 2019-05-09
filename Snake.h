#ifndef SNAKE_H
#define SNAKE_H
#include <utility>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "Color.h"
#include "Food.h"
#define Max_Length 60
#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
extern int ROW;
extern int COL;
extern int GAME_OVER;
extern Food food;
class Snake {
private :
    std::pair<int,int> body[62];
    std::string snakeName;
    float headX , headY;
    int snakeNumber;
    int snakeLength;
    int snakeDierction;
    int score;
    Color headColor;
    Color bodyColor;
public:
    Snake(int,float,float,Color,Color );
    void setHeadColor(Color );
    void setBodyColor(Color );
    void setDierciotn(int );
    void setSnakeName(std::string );
    void reset();
    int getDierction();
    int getSnakeNumber();
    int getScore();
    std::string getSnakeName();
    void drawSnake();
};

#endif // SNAKE_H
