#ifndef IO_H
#define IO_H
#include "maze.h"

void draw(int x, int y, char** maze, int width, int height, int finishX, int finishY, int levelNumber, int timeRemaining, int currentScore);
void input(int &x, int &y, char** maze, int width, int height);

#endif 

