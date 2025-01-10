#ifndef TIMER_H
#define TIMER_H
#include <ctime> 

void startTimer(int timeLimitSeconds);
bool hasTimeExpired();
int getRemainingTime();

#endif 

