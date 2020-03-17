#pragma once
#include "grid.h"
#include "MazeGenerator.h"

static CellGrid grid;

void newGameScreen(int xPos, int yPos, int sideLength, int spacingX, int spaceingY, int xUnits, int yUnits) {
	newCellGrid(&grid, xPos, yPos, sideLength, spacingX, spaceingY, xUnits, yUnits);
	initGrid(&grid);
	//generateMaze(&grid);
}


void drawGameScreen() {
	drawGrid(&grid);
	printf("hi\n");
	delay(50);
}