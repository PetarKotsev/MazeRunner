// BGIFirstTest.c : Example graphic application
//


#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#define HEIGHT 1000
#define WIDTH 1800
#define PI 3.14159

struct Point
{
	int x;
	int y;
};

void main(void)
{
	// Initialise graphic window
	int gd = CUSTOM,
		gm = CUSTOM_MODE(WIDTH, HEIGHT);
	
	initgraph(&gd, &gm, "RGB");
	printf("Hello, world\n");
	setviewport(0, 0, WIDTH, HEIGHT, 1);

	// initialize variables
	int x, y;
	int n = 2000;
	int i;
	struct Point points[2000];
	char buf[100];

	// Populate points
	for (i = 0; i < n; i++) {
		x = cos((2 * PI / n) * (i * 1.0)) * 500 + WIDTH/2;
		y = sin((2 * PI / n) * (i * 1.0)) * 500 + HEIGHT/2;

		circle(x, y, 1);
		points[i].x = x;
		points[i].y = y;
	}

	struct Point startPoint;
	struct Point endPoint;
	float m;
	int c;
	int endPointIndex;
	int red = 255,
		green = 0,
		blue = 0;
	for (m = 2.0, c = 0; m < 99.9f; m+=0.1, c++) {
		// if (red >= 0 && blue < 255) { setcolor(rgb(red, 0, blue)); blue++; red--; }
		// if (blue >= 0 && green < 255) { setcolor(rgb(0, green, blue)); green++; blue--; }
		// if (green >= 0 && red < 255) { setcolor(rgb(red, green, 0)); red++; green--; }
		setactivepage(c%2);
		clearviewport();
		snprintf(buf, 100, "Factor of %3.1f", m);
		outtextxy(20, 20, buf);
		
		for (i = 0; i < 2000; i+=10) {

			startPoint = points[i];
			printf("Start point %d: x= %d, y=%d  -->  ", i, startPoint, startPoint.y);
			endPointIndex = ((int)(m*i)) % 2000;
			endPoint = points[endPointIndex];
			printf("End point %d: x= %d, y=%d\n", endPointIndex, endPoint.x, endPoint.y);

			line(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
		}

		if (m >= 99.0f) {
			printf("executed");
			break;
		}
		
		setvisualpage(c%2);
		delay(50);
	}


	// wait for key pressed
	readkey();
	getchar();
}