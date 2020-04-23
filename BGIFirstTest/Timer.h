#pragma once
#include "time.h"

typedef struct Timer {
	time_t rawStartTime;
} Timer;

void startTimer(Timer* t) {
	t->rawStartTime = time(NULL);
}

int checkTimer(Timer* t) {
	time_t rawCurrentTime = time(NULL);
	return rawCurrentTime - t->rawStartTime;
}
