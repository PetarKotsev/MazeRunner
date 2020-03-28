#pragma once
#include "grid.h"
#include "CellPosStack.h"
#include "CellPosition.h"

CellPos currentCurPos;
CellPos nextCurPos;

int setCursorPos(CellGrid *grid, CellPos* cp);
bool hasUnvisitedNeighbours(CellGrid * grid, CellPos * cp);
void choseNeighbour(CellGrid * grid, CellPos * cp);
void destroyWallBetween(CellGrid * grid, CellPos *from, CellPos *to);
void generateMaze(CellGrid * grid);

/*
*	Define methods 
*/

void generateMaze(CellGrid * grid) {
	srand(time(NULL));
	newCellPos(grid, &currentCurPos, 0 , 0); // setting the initial start Cell
	/*setToVisitedFromGenerator(getCellAtPosition(grid, &currentCurPos));*/ 
	setGridCellToVisited(grid, &currentCurPos);  // Setting current Cell to visited

	//Initialize stack
	CellPosStack stack;
	printf("%d", grid->xUnits * grid->yUnits);
	if (newCellPosStack(&stack, grid) == NULL) {
		printf("Problem allocating stack");
	}
	// push CurrntCell to the stack
	push(&stack, &currentCurPos);

	bool index = true;

	drawGrid(grid);

	while (!isEmpty(&stack)) {
		/* Animation lines */
		setactivepage(index);
		clearviewport();
		
		// ToDo: pop from stack
		setCellPos(grid, &currentCurPos, peek(&stack)->col, peek(&stack)->row);
		pop(&stack);


		if (hasUnvisitedNeighbours(grid, &currentCurPos)) {
			//ToDo: push CurrntCell to the stack
			CellPos nextCurPos;
			push(&stack, &currentCurPos);
			choseNeighbour(grid, &nextCurPos);
			destroyWallBetween(grid, &currentCurPos, &nextCurPos);
			setGridCellToVisited(grid, &nextCurPos);
			push(&stack, &nextCurPos);
			setCellPos(grid, &currentCurPos, nextCurPos.col, nextCurPos.row);
		}
		setCursorPos(grid, &currentCurPos);

		drawGrid(grid);
		drawGridCell(grid, currentCurPos.col, currentCurPos.row, rgb(255, 255, 255));

		/* Animation statements */
		setvisualpage(index);
		index = !index;
		//delay(5);
	}
}

int setCursorPos(CellGrid * grid, CellPos * cp) {
	return setCellPos(grid, &currentCurPos, cp->col, cp->row);
}

bool hasUnvisitedNeighbours(CellGrid * grid, CellPos * cp) {
	int counter = 0;
	if (cp->row - 1 >= 0) {
		if (!isGridCellVisited(grid, cp->col, cp->row - 1)) {
			counter++;
			//drawCell(&field[cp->col][cp->row - 1], rgb(255, 0, 0));
		}
	}
	if (cp->col + 1 < grid->xUnits) {
		if (!isGridCellVisited(grid, cp->col + 1, cp->row)) {
			counter++;
			//drawCell(&field[cp->col + 1][cp->row], rgb(255, 0, 0));
		}
	}
	if (cp->row + 1 < grid->yUnits) {
		if (!isGridCellVisited(grid, cp->col, cp->row + 1)) {
			counter++;
			//drawCell(&field[cp->col][cp->row + 1], rgb(255, 0, 0));
		}
	}
	if (cp->col - 1 >= 0) {
		if (!isGridCellVisited(grid, cp->col - 1, cp->row)) {
			counter++;
			//drawCell(&field[cp->col - 1][cp->row], rgb(255, 0, 0));
		}
	}

	return counter > 0;
}

void choseNeighbour(CellGrid * grid,CellPos * cp) {
	CellPos neig[4];
	int counter = 0;
	if (cp->row - 1 >= 0) { // UP
		if (!isGridCellVisited(grid, cp->col, cp->row - 1)) {
			newCellPos(grid, &neig[counter], cp->col, cp->row - 1);
			counter++;
		}
	}
	if (cp->col + 1 < grid->xUnits) { // RIGHT
		if (!isGridCellVisited(grid, cp->col + 1, cp->row)) {
			newCellPos(grid, &neig[counter], cp->col + 1, cp->row);
			counter++;
		}
	}
	if (cp->row + 1 < grid->yUnits) { // BOTTOM
		if (!isGridCellVisited(grid, cp->col, cp->row + 1)) {
			newCellPos(grid, &neig[counter], cp->col , cp->row + 1);
			counter++;
		}
	}
	if (cp->col - 1 >= 0) { // LEFT
		if (!isGridCellVisited(grid, cp->col - 1, cp->row)) {
			newCellPos(grid, &neig[counter],cp->col - 1, cp->row);
			counter++;
		}
	}

	if (counter == 0) {
		perror("No neigbours");
	}

	int randIndex = rand() % counter;
	
	cp->col = neig[randIndex].col;
	cp->row = neig[randIndex].row;
}

void destroyWallBetween(CellGrid * grid, CellPos *from, CellPos * to) {
	if (from->col > to->col) {
		destroyCellWall(grid, from->col, from->col, LEFT_WALL);
		destroyCellWall(grid, to->col, to->row, RIGHT_WALL);
	}
	else if (from->col < to->col) {
		destroyCellWall(grid, from->col, from->row, RIGHT_WALL);
		destroyCellWall(grid, to->col, to->row, LEFT_WALL);
	}
	else if (from->row > to->row) {
		destroyCellWall(grid, from->col, from->row, TOP_WALL);
		destroyCellWall(grid, to->col, to->row, BOTTOM_WALL);
	}
	else if (from->row < to->row) {
		destroyCellWall(grid, from->col, from->row, BOTTOM_WALL);
		destroyCellWall(grid, to->col, to->row, TOP_WALL);
	}
}