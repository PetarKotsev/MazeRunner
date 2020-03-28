#pragma once
#include "grid.h"
#include "MazeGenerator.h"

CellGrid grid;

void newGameScreen(int xPos, int yPos, int sideLength, int spacingX, int spaceingY, int xUnits, int yUnits) {
	printf("build grid");
	newCellGrid(&grid, xPos, yPos, sideLength, spacingX, spaceingY, xUnits, yUnits);
	
	generateMaze(&grid);
}


void drawGameScreen() {
	drawGrid(&grid);
	printf("hi\n");
	delay(50);
}