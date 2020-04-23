#pragma once
#include "graphics.h"
#include "CellPosition.h"

static int __PlayerID = 0;

typedef struct {
	int id;
	int xPos;
	int yPos;
	CellPos gp;
	int vertacies[10];
	int color;
} Player;

Player* setPlayer(Player* pl, CellGrid* grid, int col, int row) {
	pl->id = __PlayerID++;
	CellPos gp;
	newCellPos(grid, &gp, col, row);
	pl->gp = gp;
	pl->xPos = grid->field[col][row].xPos;
	pl->yPos = grid->field[col][row].yPos;
	int playercharSideL = grid->field[col][row].dis - 1;
	pl->vertacies[0] = pl->xPos + 1;
	pl->vertacies[1] = pl->yPos + 1;
	pl->vertacies[2] = pl->xPos + 1;
	pl->vertacies[3] = pl->yPos + playercharSideL - 1;
	pl->vertacies[4] = pl->xPos + playercharSideL - 1;
	pl->vertacies[5] = pl->yPos + playercharSideL - 1;
	pl->vertacies[6] = pl->xPos + playercharSideL - 1;
	pl->vertacies[7] = pl->yPos + 1;
	pl->color = rgb(200, 50, 50);
}

Player* setPlayerPos(Player* pl, CellGrid* grid, CellPos* cp) {
	CellPos gp;
	newCellPos(grid, &gp, cp->col, cp->row);
	pl->gp = gp;
	pl->xPos = grid->field[cp->row][cp->col].xPos;
	pl->yPos = grid->field[cp->row][cp->col].yPos;
	int playercharSideL = grid->field[cp->row][cp->col].dis - 1;
	pl->vertacies[0] = pl->xPos + 1;
	pl->vertacies[1] = pl->yPos + 1;
	pl->vertacies[2] = pl->xPos + 1;
	pl->vertacies[3] = pl->yPos + playercharSideL - 1;
	pl->vertacies[4] = pl->xPos + playercharSideL - 1;
	pl->vertacies[5] = pl->yPos + playercharSideL - 1;
	pl->vertacies[6] = pl->xPos + playercharSideL - 1;
	pl->vertacies[7] = pl->yPos + 1;
}

void drawPlayer (Player* pl) {
	int poly[10];
	poly[0] = pl->vertacies[0];
	poly[1] = pl->vertacies[1];
	poly[2] = pl->vertacies[2];
	poly[3] = pl->vertacies[3];
	poly[4] = pl->vertacies[4];
	poly[5] = pl->vertacies[5];
	poly[6] = pl->vertacies[6];
	poly[7] = pl->vertacies[7];
	poly[8] = pl->vertacies[0];
	poly[9] = pl->vertacies[1];
	
	setcolor(pl->color);
	setfillstyle(0, pl->color);
	fillpoly(5, poly);
	setcolor(rgb(255, 255, 255));
}