#ifndef FOOD_H
#define FOOD_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include <stdlib.h>
#include "Color.h"
extern int ROW;
extern int COL;
class Food {
private :
    bool needFood;
    float foodX,foodY;
    void generateFood(float &,float &);
    Color foodColor;
public:
    Food(Color );
    void drawFood();
    void setNeedFood(bool);
    void setFoodColor(Color);
    float getFoodX();
    float getFoodY();

};

#endif // FOOD_H
