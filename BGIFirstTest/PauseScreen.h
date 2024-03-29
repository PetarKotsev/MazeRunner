#pragma once
#include "graphics.h"

void drawPouseScreen() {
	clearviewport();
	rectangle(20, 20, 980, 680);
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	settextjustify(CENTER_TEXT, CENTER_TEXT);

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 60);
	outtextxy(midx, midy - 150, "PAUSE");

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 15);
	outtextxy(midx, midy + 250, "To continue press space.        To close the game press ESC.");
}