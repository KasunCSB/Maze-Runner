#include "score.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;
const string SCORE_FILE = "C:\\Windows\\Temp\\score.dat";

// Function to handle the start of a new game for the player
void handlePlayerStart(string& playerName) {
    cout << "\r" << "Enter your name: ";
    cin >> playerName;
    
    // Check if the player is new and save an initial score of 0 if so
    if (isNewPlayer(playerName)) {
        saveScore(playerName, 0);
    }
}

// Function to check if a player is new based on the score file
bool isNewPlayer(const string& playerName) {
    ifstream inputFile(SCORE_FILE.c_str());
    string name;
    int score;

    if (!inputFile.is_open()) {
        return true; 
    }

    while (inputFile >> name >> score) {
        if (name == playerName) {
            inputFile.close();
            return false;
        }
    }

    inputFile.close();
    return true;
}

// Function to save or update a player's score
void saveScore(const string& playerName, int finalScore) {
    ifstream inputFile(SCORE_FILE.c_str());
    ofstream tempFile;
    bool playerExists = false;
    string name;
    int score;

    if (!inputFile.is_open()) {
        // Create a new score file if it doesn't exist
        tempFile.open(SCORE_FILE.c_str());
        if (!tempFile.is_open()) {
            cerr << "Error: Unable to create score file.\n";
            return;
        }
        tempFile << playerName << " " << finalScore << "\n";
        tempFile.close();
        return;
    }

    // Create a temporary file to write updated scores
    tempFile.open("temp.score");
    if (!tempFile.is_open()) {
        cerr << "Error: Unable to open temporary file for writing.\n";
        inputFile.close();
        return;
    }

    // Update or add the player's score
    while (inputFile >> name >> score) {
        if (name == playerName) {
            score = max(score, finalScore); // Keep the highest score
            playerExists = true;
        }
        tempFile << name << " " << score << "\n";
    }

    inputFile.close();

    if (!playerExists) {
        tempFile << playerName << " " << finalScore << "\n";
    }

    tempFile.close();

    // Replace old score file with updated one
    if (remove(SCORE_FILE.c_str()) != 0) {
        cerr << "Error: Unable to remove old score file.\n";
        return;
    }

    if (rename("temp.score", SCORE_FILE.c_str()) != 0) {
        cerr << "Error: Unable to rename temporary score file.\n";
    }
}

// Function to load and display the leaderboard
void loadLeaderboard() {
    ifstream inputFile(SCORE_FILE.c_str());

    if (!inputFile.is_open()) {
        cout << "\nNo leaderboard data found.";
        return;
    }

    string names[100];
    int scores[100];
    int count = 0;

    string name;
    int score;

    // Read scores from the file
    while (inputFile >> name >> score) {
        if (count < 100) {  
            names[count] = name;
            scores[count] = score;
            count++;
        }
    }

    inputFile.close();

    // Sort scores in descending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (scores[j] < scores[j + 1]) {
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }

    int limit = min(count, 10);
    
    // Display top scores
    cout << string(20, ' ') << "---" << " Top " << limit << " ---" << endl;
    for (int i = 0; i < limit; i++) {
        cout << "\n" << (i + 1) << ". " << names[i] << ": " << scores[i];
    }
}

// Function to calculate the score based on time
double calculateScore(int timeAllocated, int timeSpent) {
    return (static_cast<double>(timeAllocated - timeSpent) / timeAllocated) * 100;
}

