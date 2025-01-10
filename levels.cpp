#include "levels.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

// Function to set up a level
void setup(Level &level, int index, int width, int height) {
    level.x = 2; // Initial player x position
    level.y = 1; // Initial player y position
    level.maze = new char*[height]; // Allocate memory for the maze
    
    for (int i = 0; i < height; ++i) {
        level.maze[i] = new char[width + 1]; // Allocate memory for each row
    }
    
    // Copy maze template to the level's maze
    for (int i = 0; i < height; ++i) {
        strncpy(level.maze[i], mazeTemplates[index][i], width);
        level.maze[i][width] = '\0'; // Null-terminate each row
    }

    srand(time(0)); // Seed the random number generator

    // Randomly place the finish point in the maze
    do {
        level.finishX = rand() % width;
        level.finishY = rand() % height;
    } while (level.maze[level.finishY][level.finishX] == '±' || (level.finishX == level.x && level.finishY == level.y));
}

// Function to check if the game is over (i.e., player has reached the finish point)
bool gameOver(const Level &level) {  
    return level.x == level.finishX && level.y == level.finishY;
}

