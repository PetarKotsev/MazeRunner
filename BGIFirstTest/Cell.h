#pragma once
/*
*	Cell
*/
static int __CellIndex = 0;

typedef struct{
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

Cell setCell(Cell *c, int x, int y, int sideLength, int col, int row) {
	c->index = __CellIndex++;
	c->xPos = x;
	c->yPos = y;
	c->dis = sideLength;
	c->row = row;
	c->col = col;
	c->hasTopWall = true;
	c->hasRightWall = true;
	c->hasBottomWall = true;
	c->hasLeftWall = true;
	c->visitedFromGenerator = false;
	c->vertacies[0] = x;
	c->vertacies[1] = y;
	c->vertacies[2] = x;
	c->vertacies[3] = y + sideLength;
	c->vertacies[4] = x + sideLength;
	c->vertacies[5] = y + sideLength;
	c->vertacies[6] = x + sideLength;
	c->vertacies[7] = y;
}

bool isCellVisited( Cell * c) {
	return c->visitedFromGenerator;
}

/*	Draw walls  */

static char __buff[40]; // for text printing

void drawWalls(Cell *sq) {
	if (sq->hasLeftWall)
		line(sq->vertacies[0], sq->vertacies[1], sq->vertacies[2], sq->vertacies[3]);

	if (sq->hasBottomWall)
		line(sq->vertacies[2], sq->vertacies[3], sq->vertacies[4], sq->vertacies[5]);

	if (sq->hasRightWall)
		line(sq->vertacies[4], sq->vertacies[5], sq->vertacies[6], sq->vertacies[7]);

	if (sq->hasTopWall)
		line(sq->vertacies[6], sq->vertacies[7], sq->vertacies[0], sq->vertacies[1]);

	//printf("Cell -> %d\n", sq->index);

	//snprintf(__buff, 40, "%d", sq->index);
	//outtextxy(sq->xPos + 1, sq->yPos + 1, __buff);
}

void setToVisitedFromGenerator(Cell *c) {
	c->visitedFromGenerator = true;
}

void drawCell(Cell *c, int color) {
	int poly[10];
	poly[0] = c->vertacies[0];
	poly[1] = c->vertacies[1];
	poly[2] = c->vertacies[2];
	poly[3] = c->vertacies[3];
	poly[4] = c->vertacies[4];
	poly[5] = c->vertacies[5];
	poly[6] = c->vertacies[6];
	poly[7] = c->vertacies[7];
	poly[8] = c->vertacies[0];
	poly[9] = c->vertacies[1];

	setcolor(rgb(0, 100, 0));
	setfillstyle(0 , color);
	fillpoly(5, poly);
	setcolor(rgb(255,255,255));
}