#ifndef UI_H
#define UI_H

int getMenuChoice();
void displayCredits();
void displayHowToPlay();
void displayLeaderboard();
void showExitMessage();
void showInvalidChoiceMessage();
void showGameOverMessage(int score);
void showCongratulationsMessage(int score);
void waitForReturnToMenu();
void waitForNextLevel();

#endif 

