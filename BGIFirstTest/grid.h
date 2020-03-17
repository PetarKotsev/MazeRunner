#pragma once
#include "Cell.h"

/*Grid structure*/

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

/* Grid cell Position structure */

typedef struct {
	CellGrid * grid; // container Grid
	int col; // x axis
	int row; // y axis
} CellPos;


/* Point variable */

typedef struct Point
{
	int x;
	int y;
} Point;


/*	Field init	*/

Cell ** newCellGrid(CellGrid * cg, int xPos, int yPos, int cellSidelength, int spacingX, int spacingY, int xUnits, int yUnits) {
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
			perror("Failed to allocate memory for gridcell index %d", i);
			return NULL;
		}
	}
	return cg->field;
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


/*
*	Initiealize grid
*/

typedef enum {
	TOP_WALL = 0,
	RIGHT_WALL = 1,
	BOTTOM_WALL = 2,
	LEFT_WALL = 3
} WallDir;

void destroyCellWall(CellGrid * grid,CellPos *cp, WallDir WallIndex) {
	if (WallIndex == TOP_WALL) {
		grid->field[cp->row][cp->col].hasTopWall = false;
	}
	if (WallIndex == RIGHT_WALL) {
		grid->field[cp->row][cp->col].hasRightWall = false;
	}
	if (WallIndex == BOTTOM_WALL) {
		grid->field[cp->row][cp->col].hasBottomWall = false;
	}
	if (WallIndex == LEFT_WALL) {
		grid->field[cp->row][cp->col].hasLeftWall = false;
	}
}



void initGrid(CellGrid * grid) {
	for (int i = 0; i < grid->yUnits; i++) {
		for (int j = 0; j < grid->xUnits; j++) {
			setCell( &grid->field[i][j], 
					 j * grid->cellSidelength + grid->spacingX*j + grid->xPos,
					 i * grid->cellSidelength + grid->spacingY*i + grid->yPos,
					 grid->cellSidelength, 
					 j, 
					 i);
			printf("row -> %d; col -> %d\n", i, j);
		}
	}
}


/*
*	Draw grid
*/
void drawGrid(CellGrid * grid) {
	//	printf("RUN\n");
	int lastColor = getcolor();
	setcolor(rgb(200,200,200));
	for (int i = 0; i < grid->yUnits; i++) {
		for (int j = 0; j < grid->xUnits; j++) {
			drawWalls(&grid->field[i][j]);
		}
	}
	setcolor(lastColor);
}

void drawGridCell(CellGrid * grid, CellPos * cp, int color) {
	drawCell(&grid->field[cp->row][cp->col], color);
}


/*
*	Cell position
*/

CellPos * newCellPos(CellGrid * grid, CellPos *cp, int col, int row) {
	cp->grid = grid;
	if (col >= 0 && col < cp->grid->xUnits &&
		row >= 0 && row < cp->grid->yUnits) {
		cp->col = col;
		cp->row = row;
		return cp;
	}
	return NULL;
}

CellPos * setCellPos(CellPos* cp, int newCol, int newRow) {
	//printf("{%d, %d} -> to {%d, %d}\n", cp->col, cp->row, newCol, newRow);

	if (newCol >= 0 && newCol < cp->grid->xUnits &&
		newRow >= 0 && newRow < cp->grid->yUnits) {
		cp->col = newCol;
		cp->row = newRow;
		return cp;
	}
	return NULL;
}

void setGridCellToVisited(CellPos * cp) {
	setToVisitedFromGenerator(&cp->grid->field[cp->row][cp->col]);
}

bool isGridCellVisited(CellGrid * grid, int col, int row) {
	return isCellVisited(&grid->field[row][col]);
}

Cell * getCellAtPosition(CellGrid * grid, CellPos * cp) {
	return &grid->field[cp->row][cp->col];
}