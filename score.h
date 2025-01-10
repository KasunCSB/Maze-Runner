#ifndef SCORE_H
#define SCORE_H
#include <string>

void handlePlayerStart(std::string& playerName);
void saveScore(const std::string& playerName, int finalScore);
void loadLeaderboard();
double calculateScore(int timeAllocated, int timeSpent);
bool isNewPlayer(const std::string& playerName);

#endif 

