#include "timer.h"

static clock_t startTime; // Start time of the timer
static int timeLimit = 0; // Time limit in seconds

// Function to start the timer with a specified time limit
void startTimer(int timeLimitSeconds) {
    timeLimit = timeLimitSeconds;
    startTime = clock(); 
}

// Function to check if the time limit has expired
bool hasTimeExpired() {
    clock_t elapsedTime = clock() - startTime;
    return elapsedTime / CLOCKS_PER_SEC >= timeLimit; 
}

// Function to get the remaining time
int getRemainingTime() {
    clock_t elapsedTime = clock() - startTime;
    int remainingTime = timeLimit - (elapsedTime / CLOCKS_PER_SEC);
    return (remainingTime > 0) ? remainingTime : 0;
}

