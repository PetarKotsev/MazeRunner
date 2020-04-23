#pragma once
#include "time.h"

typedef struct Timer {
	time_t rawStartTime;
	time_t rawEndTime;
} Timer;

void startTimer(Timer* t) {
	t->rawStartTime = time(NULL);
	t->rawEndTime = 0;
}

void stopTimer(Timer * t) {
	t->rawEndTime = time(NULL);
}

int checkTimer(Timer* t) {
	time_t rawCurrentTime = time(NULL);
	return rawCurrentTime - t->rawStartTime;
}

int stoppedTimer(Timer* t) {
	return t->rawEndTime - t->rawStartTime;
}