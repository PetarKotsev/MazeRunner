#pragma once
#include "graphics.h"
#include "CellPosition.h"

static int __GoalID = 0;

typedef struct {
	int id;
	int xPos;
	int yPos;
	CellPos gp;
	int vertacies[10];
	int color;
} Goal;

Goal* setGoal(Goal* g, CellGrid* grid, int col, int row) {
	g->id = __GoalID++;
	CellPos gp;
	newCellPos(grid, &gp, col, row);
	g->gp = gp;
	g->xPos = grid->field[col][row].xPos;
	g->yPos = grid->field[col][row].yPos;
	int playercharSideL = grid->field[col][row].dis - 1;
	g->vertacies[0] = g->xPos + 1;
	g->vertacies[1] = g->yPos + 1;
	g->vertacies[2] = g->xPos + 1;
	g->vertacies[3] = g->yPos + playercharSideL - 1;
	g->vertacies[4] = g->xPos + playercharSideL - 1;
	g->vertacies[5] = g->yPos + playercharSideL - 1;
	g->vertacies[6] = g->xPos + playercharSideL - 1;
	g->vertacies[7] = g->yPos + 1;
	g->color = rgb(255, 250, 10);
}

void drawGoal(Goal* g) {
	int poly[10];
	poly[0] = g->vertacies[0];
	poly[1] = g->vertacies[1];
	poly[2] = g->vertacies[2];
	poly[3] = g->vertacies[3];
	poly[4] = g->vertacies[4];
	poly[5] = g->vertacies[5];
	poly[6] = g->vertacies[6];
	poly[7] = g->vertacies[7];
	poly[8] = g->vertacies[0];
	poly[9] = g->vertacies[1];

	setcolor(g->color);
	setfillstyle(0, g->color);
	fillpoly(5, poly);
	setcolor(rgb(255, 255, 255));
}