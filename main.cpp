#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
//#include <windows.h>
#include "Color.h"
#include "Grid.h"
#include "Snake.h"
#include "Food.h"
using namespace std;
int FPS = 10;
int ROW = 30;
int COL = 30;
int GAME_OVER = 0;
bool pause = true;
Grid grid;
Food food(Color(0.51,0.75,0.31));
Snake snake1(1,ROW/2 +1,COL/2,Color(0.0,1.0,0.0),Color(0.0,0.0,1.0));
Snake snake2(2,ROW/2 -1,COL/2,Color(1.0,1.0,0.0),Color(0.0,1.0,1.0));
string getResult(Snake,Snake );
void initializePlayers();
void init();
void reshape (int ,int );
void display();
void keyboard2(int ,int ,int);
void keyboard(unsigned char ,int ,int);
void timer(int );
int main(int argcp,char ** argv) {
    initializePlayers();
    glutInit(&argcp,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(640,460);
    glutCreateWindow("SNAKE");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glutSpecialFunc(keyboard2);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
void reshape (int w,int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,ROW,0.0,COL,-1.0,1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.13,0.561,0.41,1.0);
    grid.drawGrid();
    food.drawFood();
    snake1.drawSnake();
    snake2.drawSnake();
    glutSwapBuffers();
    if (GAME_OVER != 0) {
        string result = getResult(snake1,snake2);
//        MessageBox(NULL,result.c_str(),"!!!GAME OVER!!!",0);
        snake1.reset();
        snake2.reset();

    }
}
void init() {
    grid.setBackgroundColor(Color(0.0,0.0,0.0));
    grid.setLineColor(Color(1.0,1.0,1.0));
    grid.setEdgesColor(Color(1.0,0.0,0.0));
    grid.setResolution(ROW,COL);
}
void timer(int) {
    if (pause == false)
        glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}
void keyboard(unsigned char key,int ,int) {
    switch (key) {
    case 'w' :
        if (snake2.getDierction() != DOWN)
            snake2.setDierciotn(UP);
        break;
    case 's' :
        if (snake2.getDierction() != UP)
            snake2.setDierciotn(DOWN);
        break;
    case 'd' :
        if (snake2.getDierction() != LEFT)
            snake2.setDierciotn(RIGHT);
        break;
    case 'a' :
        if (snake2.getDierction() != RIGHT)
            snake2.setDierciotn(LEFT);
        break;
    case '=' :
        FPS++;
        break;
    case '-' :
        FPS--;
        if (FPS<2) {
            FPS = 2;
        }
        break;
    case 32 :
        pause = !pause;
        break;
    case 27 :
        exit(0);
    }
}
void keyboard2(int key,int ,int) {
    switch (key) {
    case GLUT_KEY_UP :
        if (snake1.getDierction() != DOWN)
            snake1.setDierciotn(UP);
        break;
    case GLUT_KEY_DOWN :
        if (snake1.getDierction() != UP)
            snake1.setDierciotn(DOWN);
        break;
    case GLUT_KEY_RIGHT :
        if (snake1.getDierction() != LEFT)
            snake1.setDierciotn(RIGHT);
        break;
    case GLUT_KEY_LEFT :
        if (snake1.getDierction() != RIGHT)
            snake1.setDierciotn(LEFT);
        break;
    }
    glutPostRedisplay();
}
void initializePlayers() {
    string name1,name2;
    start :
    cout << "Enter Player 1 name : ";
    cin >> name1;
    cout << "Enter Player 2 name : ";
    cin >> name2;
    if (name1 == name2) {
        cout << "Wrong , Try Again .\n";
        goto start;
    }
    snake1.setSnakeName(name1);
    snake2.setSnakeName(name2);
}
string getResult(Snake player1,Snake player2) {
    string result = "THE WINNER IS : " + (GAME_OVER ==player1.getSnakeNumber()
                                      ?  player2.getSnakeName() : player1.getSnakeName()) + "\n";
    result += player1.getSnakeName() + " : " + to_string(player1.getScore()) + "\n";
    result += player2.getSnakeName() + " : " + to_string(player2.getScore()) + "\n";
    return result;
}
