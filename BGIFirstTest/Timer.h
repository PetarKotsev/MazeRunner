#pragma once
#include "time.h"

typedef struct Timer {
	time_t rawStartTime;
	time_t rawEndTime;
};

void startTimer(Timer* t) {
	t->rawStartTime = time(NULL);
}

void stopTimer(Timer * t) {
	t->rawEndTime = time(NULL);
}

int checkTimer(Timer* t) {
	return t->rawEndTime - t->rawStartTime;
}

