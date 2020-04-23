#pragma once
#include <graphics.h>
#include "GameTimer.h"


void drawGameHud() {
	rectangle(20, 20, 680, 680);

	rectangle(700, 20, 980, 320);
	settextstyle(0, 0, 15);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(840, 120, "Time:");
	rectangle(700, 340, 980, 680);
}