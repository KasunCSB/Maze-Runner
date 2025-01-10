#ifndef LEVELS_H
#define LEVELS_H
#include "maze.h"

struct Level {
    int x, y;                
    int finishX, finishY;    
    char** maze;             
};

void setup(Level &level, int index, int width, int height);
bool gameOver(const Level &level);

#endif 

