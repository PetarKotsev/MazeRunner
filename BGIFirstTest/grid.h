#pragma once
#include "Cell.h"

/* Grid structure */

typedef struct {
	int xPos;
	int yPos;
	int cellSidelength;
	int spacingX;
	int spacingY;
	int xUnits;
	int yUnits;
	Cell **field;
} CellGrid;

typedef enum WallDir{
	TOP_WALL = 0,
	RIGHT_WALL = 1,
	BOTTOM_WALL = 2,
	LEFT_WALL = 3
} WallDir;


/*	Field init  */ 


/*
*	Initiealize grid
*/

static void initGrid(CellGrid * grid) {
	for (int i = 0; i < grid->yUnits; i++) {
		for (int j = 0; j < grid->xUnits; j++) {
			setCell(&grid->field[i][j],
				j * grid->cellSidelength + grid->spacingX*j + grid->xPos,
				i * grid->cellSidelength + grid->spacingY*i + grid->yPos,
				grid->cellSidelength,
				j,
				i);
			printf("row -> %d; col -> %d\n", i, j);
		}
	}
}

CellGrid * newCellGrid(CellGrid * cg, int xPos, int yPos, int cellSidelength, int spacingX, int spacingY, int xUnits, int yUnits) {
	cg->xPos = xPos;
	cg->yPos = yPos;
	cg->cellSidelength = cellSidelength;
	cg->spacingX = spacingX;
	cg->spacingY = spacingY;
	cg->xUnits = xUnits;
	cg->yUnits = yUnits; 

	cg->field = (Cell**)calloc(yUnits, sizeof(Cell*));
	if (cg->field == NULL) {
		perror("Failed to allocate memory for grid");
		return NULL;
	}

	for (int i = 0; i < yUnits; i++) {
		cg->field[i] = (Cell*)calloc(xUnits, sizeof(Cell));
		if (cg->field[i] == NULL) {
			printf("Failed to allocate memory for gridcell index %d", i);
			return NULL;
		}
	}
	initGrid(cg);
	return cg;
}

Cell ** reConfigCellGrid(CellGrid * cg, int new_xPos, int new_yPos, int new_cellSidelength, int new_spacingX, int new_spacingY, int new_xUnits, int new_yUnits) {
	cg->xPos = new_xPos;
	cg->yPos = new_yPos;
	cg->cellSidelength = new_cellSidelength;
	cg->spacingX = new_spacingX;
	cg->spacingY = new_spacingY;
	cg->xUnits = new_xUnits;
	cg->yUnits = new_yUnits;

	cg->field = (Cell**)realloc(cg->field, new_yUnits);

	for (int i = 0; i < new_yUnits; i++) {
		cg->field[i] = (Cell*)realloc(cg->field[i], new_xUnits);
	}

	if (cg->field == NULL) {
		return NULL;
		printf("Failed to allocate memory for grid");
	}
	return cg->field;
}

void destroyCellWall(CellGrid * grid, int col, int row, WallDir WallIndex) {
	if (WallIndex == TOP_WALL) {
		grid->field[row][col].hasTopWall = false;
	}
	if (WallIndex == RIGHT_WALL) {
		grid->field[row][col].hasRightWall = false;
	}
	if (WallIndex == BOTTOM_WALL) {
		grid->field[row][col].hasBottomWall = false;
	}
	if (WallIndex == LEFT_WALL) {
		grid->field[row][col].hasLeftWall = false;
	}
}

bool isWallInDir(CellGrid* grid, int col, int row, int dir) {
	switch (dir)
	{
	case 0:
		return grid->field[row][col].hasTopWall;
		break;
	case 1:
		return grid->field[row][col].hasRightWall;
		break;
	case 2:
		return grid->field[row][col].hasBottomWall;
		break;
	case 3:
		return grid->field[row][col].hasLeftWall;
		break;
	}
}


/*
*	Draw grid
*/
void drawGrid(CellGrid * grid) {
	int lastColor = getcolor();
	setcolor(rgb(200,200,200));
	for (int i = 0; i < grid->yUnits; i++) {
		for (int j = 0; j < grid->xUnits; j++) {
			drawWalls(&grid->field[i][j]);
		}
	}
	setcolor(lastColor);
}

void drawGridCell(CellGrid * grid, int col, int row, int color) {
	drawCell(&grid->field[row][col], color);
}

/*
*	Cell position
*/

bool isGridCellVisited(CellGrid * grid, int col, int row) {
	return isCellVisited(&grid->field[row][col]);
}