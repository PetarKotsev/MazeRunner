#pragma once
/*
*	Cell
*/
extern int __CellIndex = 0;

typedef struct Cell{
	int index;
	int xPos;
	int yPos;
	int dis;
	int row;
	int col;
	bool hasTopWall;
	bool hasRightWall;
	bool hasBottomWall;
	bool hasLeftWall;
	bool visitedFromGenerator;
	int vertacies[10];
} Cell;

Cell * setCell(Cell *c, int x, int y, int sideLength, int col, int row);
extern bool isCellVisited(Cell * c);

/*	Draw walls  */
extern void drawWalls(Cell *sq);
extern void setToVisitedFromGenerator(Cell *c);
extern void drawCell(Cell *c, int color);