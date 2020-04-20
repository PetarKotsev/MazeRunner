#pragma once
#include "grid.h"
#include "MazeGenerator.h"
#include "GameHud.h"

CellGrid grid;

void newGameScreen(int xPos, int yPos, int sideLength, int spacingX, int spaceingY, int xUnits, int yUnits) {
	printf("build grid");
	newCellGrid(&grid, xPos, yPos, sideLength, spacingX, spaceingY, xUnits, yUnits);
	generateMaze(&grid);
	clearviewport();
}


void drawGameScreen() {
	drawGrid(&grid);
	drawGameHud();
}