#pragma once
#include "Timer.h"

typedef struct GameTimer {
	Timer timer;
} GameTimer;

void startGameTimer(GameTimer* t) {
	startTimer(&t->timer);
}

void drawGameTimer(GameTimer* t) {
	char buff[9];
	int hours   = checkTimer(&t->timer) / 3600;
	int minutes = checkTimer(&t->timer) % 3600 / 60;
	int seconds = checkTimer(&t->timer) % 60;
	sprintf_s(buff, 9, "%2d %2d %2d", hours, minutes, seconds);
	outtextxy(840, 145, buff);
}