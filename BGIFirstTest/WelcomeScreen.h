#pragma once
#include "Counter.h"
static bool animationFlag = true;

void drawWelcomeScreen() {
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;

	rectangle(20, 20, 980, 680);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 70 + (getGlobalCounter() / 5 % 5));
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setcolor(rgb(141, 110, 99));
	outtextxy(midx + 2, midy - 148, "THE MAZE RUNNER");
	setcolor(rgb(255, 167, 38));
	outtextxy(midx, midy - 150, "THE MAZE RUNNER");


	settextstyle(COMPLEX_FONT, HORIZ_DIR, 10);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setcolor(rgb(130,130,130));

	outtextxy(midx, midy -  0, "Space       -    Pause/Play");
	outtextxy(midx, midy + 30, "Arrows/WASD -          Move");
	setcolor(rgb( abs (10 * (getGlobalCounter() % 40) - 200),
				  abs (10 * (getGlobalCounter() % 40) - 200), 
				  abs (10 * (getGlobalCounter() % 40) - 200)));

	
	outtextxy(midx, midy + 120, "( Press SPACE to start the game. )");
	delay(50);
	setcolor(rgb(255,255,255));
}

