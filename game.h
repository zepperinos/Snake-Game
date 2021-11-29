#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2

#define MAX 65

void initGrid(int,int);
void drawGrid();
void snake();
void spawnFood();
void random(int&,int&);

#endif
