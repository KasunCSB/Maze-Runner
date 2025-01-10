#include <iostream>
#include <conio.h>
#include "ui.h"
#include "score.h"

using namespace std;

void displayAsciiArt() {
    cout << "\n8b    d8    db    8888P 888888 \n";
    cout << "88b  d88   dPYb     dP  88__   \n";
    cout << "88YbdP88  dP__Yb   dP   88\"\"   \n";
    cout << "88 YY 88 dP\"\"\"\"Yb d8888 888888 \n";
    cout << "\n88\"\"Yb 88   88 88b 88 88b 88 888888 88\"\"Yb \n";
    cout << "88__dP 88   88 88Yb88 88Yb88 88__   88__dP \n";
    cout << "88\"Yb  Y8   8P 88 Y88 88 Y88 88\"\"   88\"Yb  \n";
    cout << "88  Yb `YbodP' 88  Y8 88  Y8 888888 88  Yb \n";
}

int getMenuChoice() {
    system("cls");
    displayAsciiArt();
    cout << "\n" << string(23, '-') << " Menu " << string(24, '-') << endl;
    cout << "\n1. Play";
    cout << "\n2. Leaderboard";
    cout << "\n3. How to Play";
    cout << "\n4. Credits";
    cout << "\n5. Exit\n";
    cout << "\n" << string(53, '-') << endl;
    cout << "\nSelect an option: ";
    return _getch() - '0';  
}

void displayCredits() {
    system("cls");
    displayAsciiArt();
    cout << "\n" << string(20, '-') << " Credits " << string(20, '-') << endl;
    cout << "\nMaze Runner Game";
    cout << "\nVersion: 6.0\n";
    cout << "\nDeveloped by: Group II, IM 2022, UoK";
    cout << "\nDeveloped for: Final Project of Semester I";
    cout << "\nGroup Members: Kasun, Dimuthu, Sanjana, Dilthara\n";
    cout << "\n" << string(49, '-') << endl;
    waitForReturnToMenu();
}

void displayHowToPlay() {
    system("cls");
    displayAsciiArt();
    cout << "\n" << string(20, '-') << " How to Play " << string(20, '-') << endl;
    cout << "\nUse 'a' 's' 'w' 'd' keys to navigate through the maze.\n";
    cout << "Reach the finish point before time runs out.\n";
    cout << "\n" << string(53, '-') << endl;
    waitForReturnToMenu();
}

void displayLeaderboard() {
    system("cls");
    displayAsciiArt();
    cout << "\n" << string(20, '-') << " Leaderboard " << string(20, '-') << endl;
    loadLeaderboard();
    cout << "\n\n" << string(53, '-') << endl;
    waitForReturnToMenu();
}

void showExitMessage() {
    cout << "\nExiting the game. Goodbye!\n";
}

void showInvalidChoiceMessage() {
    cout << "\nInvalid choice! Please select a valid option.\n";
    _getch();  
}

void showGameOverMessage(int score) {
	system("cls");
	displayAsciiArt();
    cout << "\n\nTime's up! Game Over.";
    cout << "\nScore: " << score << endl;
    waitForReturnToMenu();
}

void showCongratulationsMessage(int score) {
	system("cls");
	displayAsciiArt();
    cout << "\n\nCongrats!";
	cout << "\nYou've finished the game!";
    cout << "\n\nScore: " << score;
    waitForReturnToMenu();
}

void waitForReturnToMenu() {
    cout << "\nPress any key to return to the menu...";
    _getch();  
}

void waitForNextLevel() {
    cout << "\nPress any key to continue...";
    _getch();  
}

