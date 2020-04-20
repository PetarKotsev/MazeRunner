#include "graphics.h"

void drawCountdownScreen() {
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	settextjustify(CENTER_TEXT, CENTER_TEXT);


	settextstyle(COMPLEX_FONT, HORIZ_DIR, 60);
	outtextxy(midx, midy - 150, "Starting in:");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 100);
	outtextxy(midx, midy - 50, "3");
	delay(1000);
	clearviewport();

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 60);
	outtextxy(midx, midy - 150, "Starting in:");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 100);
	outtextxy(midx, midy - 50, "2");
	delay(1000);
	clearviewport();

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 60);
	outtextxy(midx, midy - 150, "Starting in:");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 100);
	outtextxy(midx, midy - 50, "1");
	delay(1000);
	clearviewport();

}