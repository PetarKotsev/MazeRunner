#pragma once
/*
*	Point variable
*/

typedef struct Point
{
	int x;
	int y;
} Point;

/*
*	Cell position
*/

typedef struct {
	int col; // x axis
	int row; // y axis
} CellPos;

int newCellPos(CellPos *cp, int col, int row) {
	if (col >= 0 && col < cp->grid->xUnits &&
		row >= 0 && row < cp->grid->yUnits) {
		cp->col = col;
		cp->row = row;
		return 1;
	}
	return 0;
}

int setCellPos(CellPos* cp, int newCol, int newRow) {
	//printf("{%d, %d} -> to {%d, %d}\n", cp->col, cp->row, newCol, newRow);

	if (newCol >= 0 && newCol < cp->grid->xUnits &&
		newRow >= 0 && newRow < cp->grid->yUnits) {
		cp->col = newCol;
		cp->row = newRow;
		return 0;
	}
	return 1;
}

void setGridCellToVisited(CellPos * cp) {
	setToVisitedFromGenerator(&cp->grid->field[cp->row][cp->col]);
}

