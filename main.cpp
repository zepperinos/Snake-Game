#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"
#include <stdlib.h>

#define COLUMNS 50
#define ROWS 50
#define FPS 10

extern short snakeDirect;
bool gameOver=false;

int score=0;

void timer_callback(int);
void display_callback();
void reshape_callback(int,int);
void kb_callback(int,int,int);

void init()
{
    glClearColor(1.0,1.0,0.5,1.0);
    initGrid(COLUMNS,ROWS);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("SNAKE");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(kb_callback);
    init();
    glutMainLoop();
    return 0;
}

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    snake();
    spawnFood();
    glutSwapBuffers();
    if(gameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50] = "Score: ";
        strcat(text,_score);
        MessageBox(NULL,text,"GAME OVER",0);
        exit(0);
    }
}

void reshape_callback(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

void kb_callback(int key,int,int)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(snakeDirect!=DOWN)
            snakeDirect=UP;
        break;
    case GLUT_KEY_DOWN:
        if(snakeDirect!=UP)
            snakeDirect=DOWN;
        break;
    case GLUT_KEY_RIGHT:
        if(snakeDirect!=LEFT)
            snakeDirect=RIGHT;
        break;
    case GLUT_KEY_LEFT:
        if(snakeDirect!=RIGHT)
            snakeDirect=LEFT;
        break;
    }
}
