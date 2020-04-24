#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include "GameFrame.h"
#include "Counter.h"

#define HEIGHT 700
#define WIDTH 1000

/*
*	Initialize grahs. drivers
*/
void initDriver() {
	int gd = CUSTOM,
		gm = CUSTOM_MODE(WIDTH, HEIGHT);

	initgraph(&gd, &gm, "RGB");
	setviewport(0, 0, WIDTH, HEIGHT, 1);

	setbkcolor(rgb(93, 64, 55));
}

int main() {
	initDriver();

	GameFrame gf;
	newGameFrame(&gf);

	readState(&gf);

	bool index = true;

	while (true) {
		setactivepage(index);
		clearviewport();

		readState(&gf);

		setvisualpage(index);
		index = !index;
		incrGlobalCounter();
	}
	

	readkey();
	closegraph();
	return 0;
}

