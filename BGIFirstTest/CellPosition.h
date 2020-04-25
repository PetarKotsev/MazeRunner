#pragma once
#include "grid.h"

/*
*	Cell position
*/

typedef struct {
	int col; // x axis
	int row; // y axis
} CellPos;

int newCellPos(CellGrid *grid, CellPos *cp, int col, int row) {
	if (col >= 0 && col < grid->xUnits &&
		row >= 0 && row < grid->yUnits) {
		cp->col = col;
		cp->row = row;
		return 1;
	}
	return 0;
}

int setCellPos(CellGrid * grid, CellPos * cp, int newCol, int newRow) {

	if (newCol >= 0 && newCol < grid->xUnits &&
		newRow >= 0 && newRow < grid->yUnits) {
		cp->col = newCol;
		cp->row = newRow;
		return 0;
	}
	return 1;
}

void setGridCellToVisited(CellGrid *grid, CellPos * cp) {
	setToVisitedFromGenerator(&grid->field[cp->row][cp->col]);
}

