#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include "Read.h"

#define HEIGHT 700
#define WIDTH 1000

/*
*	Initialize grahs. drivers
*/
static bool index = true;
void initDriver() {
	int gd = CUSTOM,
		gm = CUSTOM_MODE(WIDTH, HEIGHT);

	initgraph(&gd, &gm, "RGB");
	setviewport(0, 0, WIDTH, HEIGHT, 1);

	setbkcolor(rgb(93, 64, 55));
}

void setToNormalSettings() {
	setcolor(rgb(130,130,130));
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 4);
	settextjustify(LEFT_TEXT, LEFT_TEXT);
}

int main() {
	initDriver();

	readState();

	bool index = true;

	while (true) {
		setactivepage(index);
		clearviewport();

		readState();

		//setToNormalSettings();
		setvisualpage(index);
		index = !index;
	}
	

	readkey();
	closegraph();
	return 0;
}

