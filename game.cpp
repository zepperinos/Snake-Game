#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "game.h"

extern int score;

int gridX, gridY;
int snakeLength = 5;
bool food = true;
int foodX,foodY;
short snakeDirect = RIGHT;
extern bool gameOver;

float posX[75]={20,20,20,20,20},posY[75]={20,20,20,20,20};

void initGrid(int x, int y)
{
    gridX=x;
    gridY=y;
}

void unit (int,int);
void drawGrid()
{
    for(int x=0; x<gridX; x++)
    {
        for(int y=0;y<gridY;y++)
        {
            unit(x,y);
        }
    }
}

void unit(int x, int y)
{
    if(x==0 || y==0 || x==gridX-1 || y==gridY-1)
    {
        glLineWidth(2.25);
        glColor3f(1.0,0.0,0.0);
    }
    else
    {
        glLineWidth(1.0);
        glColor3f(1.0,1.0,1.0);
    }

    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
}

void spawnFood()
{
    if(food)
        random(foodX,foodY);
    food = false;
    glColor3f(0.0,1.0,0.0);
    glRectf(foodX,foodY,foodX+1,foodY+1);
}

void snake()
{
    for(int i=snakeLength-1; i>0; i--)
    {
        posX[i] =  posX[i-1];
        posY[i] =  posY[i-1];
    }

    if(snakeDirect==UP)
        posY[0]++;
    else if(snakeDirect==DOWN)
        posY[0]--;
    else if(snakeDirect==RIGHT)
        posX[0]++;
    else if(snakeDirect==LEFT)
        posX[0]--;

    for(int i=0; i<snakeLength; i++)
    {
        if(i==0)
            glColor3f(1.0,0.0,0.0);
        else
            glColor3f(0.0,0.0,1.0);
        glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
    }

    if(posX[0]==0 || posX[0]==gridX-1 || posY[0]==0 || posY[0]==gridY-1)
        gameOver=true;

    if(posX[0]==foodX && posY[0]==foodY)
    {
        score++;
        snakeLength++;
        if(snakeLength>MAX)
            snakeLength=MAX;
        food = true;
    }

    for(int j=1; j<snakeLength; j++)
    {
        if(posX[j]==posX[0] && posY[j]==posY[0])
            gameOver=true;
    }

}

void random(int &x,int &y)
{
    int _maxX = gridX-3;
    int _maxY = gridY-3;
    int _min = 2;
    srand(time(NULL));
    x = _min + rand() % (_maxX-_min);
    y = _min + rand() % (_maxY-_min);
}
