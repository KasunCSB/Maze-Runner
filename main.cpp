#include <conio.h>
#include "maze.h"
#include "io.h"
#include "levels.h"
#include "timer.h"
#include "score.h"
#include "ui.h"

using namespace std;

// Global variable to store the player's name
string playerName;

// Function prototypes
void startGame(Level[], int);
void freeMaze(char**, int);

int main() {
    // Array to hold levels
    Level levels[levelCount];

    while (true) {
        // Get user menu choice
        int choice = getMenuChoice();
        switch (choice) {
            case 1:
                // Start the game for the player
                handlePlayerStart(playerName); 
                startGame(levels, levelCount); 
                break;
            case 2:
                // Display leaderboard
                displayLeaderboard(); 
                break;
            case 3:
                // Show instructions on how to play
                displayHowToPlay(); 
                break;
            case 4:
                // Show game credits
                displayCredits(); 
                break;
            case 5:
                // Exit the game
                showExitMessage();  
                return 0; 
            default:
                // Show message for invalid choice
                showInvalidChoiceMessage(); 
        }
    }
}

// Function to start the game with levels
void startGame(Level levels[], int levelCount) {
    int finalScore = 0;

    // Loop through each level
    for (int i = 0; i < levelCount; ++i) {
        // Setup the level
        setup(levels[i], i, fixedWidth, fixedHeight);

        // Set time limit for the current level
        int levelTimeLimit = 15 + i * 5; 
        startTimer(levelTimeLimit);

        // Loop until the game is over
        while (!gameOver(levels[i])) {
            int timeRemaining = getRemainingTime();

            // Draw the current state of the level
            draw(levels[i].x, levels[i].y, levels[i].maze, fixedWidth, fixedHeight, levels[i].finishX, levels[i].finishY, i + 1, timeRemaining, finalScore);

            // Check if time has expired
            if (hasTimeExpired()) {
                showGameOverMessage(finalScore);  
                saveScore(playerName, finalScore);
                return;
            }

            // Handle player input
            input(levels[i].x, levels[i].y, levels[i].maze, fixedWidth, fixedHeight);
        }

        // Calculate and update the score
        finalScore += calculateScore(levelTimeLimit, levelTimeLimit - getRemainingTime());
        freeMaze(levels[i].maze, fixedHeight);

        // Wait for the next level to start
        if (i < levelCount - 1) {
            waitForNextLevel();  
        }
    }

    // Show final congratulations message and save score
    showCongratulationsMessage(finalScore);  
    saveScore(playerName, finalScore);
}

// Function to free allocated memory for the maze
void freeMaze(char** maze, int height) {
    for (int i = 0; i < height; ++i) {
        delete[] maze[i]; 
    }
    delete[] maze; 
}

