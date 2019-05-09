#ifndef GRID_H
#define GRID_H
#include <GL/gl.h>
#include <GL/glut.h>
#include "Color.h"

class Grid {
private:
    int cols,rows;
    Color backgroundColor;
    Color lineColor;
    Color edgesColor;
    void drawSquare(float,float,Color );
public:
    Grid();
    Grid(float,float,Color, Color,Color );
    void setResolution(float,float );
    void setBackgroundColor(Color );
    void setLineColor(Color );
    void setEdgesColor(Color );
    void drawGrid();
};

#endif // GRID_H
