#pragma once
#include "graphics.h"

typedef struct WinScreen {
	unsigned int time;
} WinScreen;

void newWinScreen(WinScreen* ws, int time) {
	ws->time = time;
}

void drawWinScreen(WinScreen* ws) {
	clearviewport();
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	int hours = ws->time / 3600;
	int minutes = ws->time % 3600 / 60;
	int seconds = ws->time % 60;
	char buff[20];
	settextjustify(CENTER_TEXT, CENTER_TEXT);

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 60);
	outtextxy(midx, midy - 150, "You win!!!");

	sprintf_s(buff, 20, "Time: %2d:%2d:%2d", hours, minutes, seconds);


	settextstyle(COMPLEX_FONT, HORIZ_DIR, 30);
	outtextxy(midx, midy - 50, buff);

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 15);
	outtextxy(midx, midy + 250, "To play again press space.               To close the game press ESC.");
}