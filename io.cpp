#include "io.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Function to draw the maze and game status on the console
void draw(int x, int y, char** maze, int width, int height, int finishX, int finishY, int levelNumber, int timeRemaining, int currentScore) {
    system("cls"); // Clear the screen
    cout << ".  .           .__" << endl;
    cout << "|\\/| _.__. _   [__). .._ ._  _ ._." << endl;
    cout << "|  |(_] /_(/,  |  \\(_|[ )[ )(/,[" << endl;
    cout << endl;
    cout << "Level: " << setw(2) << levelNumber << setw(11)
         << "Score: " << setw(3) << currentScore << setw(11)
         << "Time: " << setw(2) << timeRemaining << " sec" << endl;
    cout << endl;

    // Draw the maze
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == y && j == x)
                cout << '+';
            else if (i == finishY && j == finishX)
                cout << '*';
            else
                cout << maze[i][j];
        }
        cout << endl;
    }
}


// Function to handle user input for moving the player in the maze
void input(int &x, int &y, char** maze, int width, int height) {
    char key = _getch(); // Get key press without echoing to console
    
    switch (key) {
        case 'w':
            // Move up
            if (maze[y - 1][x] != '±') y--;
            break;
        case 's':
            // Move down
            if (maze[y + 1][x] != '±') y++;
            break;
        case 'a':
            // Move left
            if (maze[y][x - 1] != '±') x--;
            break;
        case 'd':
            // Move right
            if (maze[y][x + 1] != '±') x++;
            break;
    }
}

