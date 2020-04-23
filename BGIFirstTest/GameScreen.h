#pragma once
#include "grid.h"
#include "MazeGenerator.h"
#include "GameHud.h"
#include "Player.h"
#include "Goal.h"


typedef struct GameScreen{
	CellGrid grid;
	Player player;
	Goal goal;
} GameScreen;

GameScreen* newGameScreen(GameScreen* gs, int xPos, int yPos, int sideLength, int spacingX, int spaceingY, int xUnits, int yUnits) {
	newCellGrid(&gs->grid, xPos, yPos, sideLength, spacingX, spaceingY, xUnits, yUnits);
	setPlayer(&gs->player, &gs->grid, 0, 0);
	setGoal(&gs->goal, &gs->grid, gs->grid.xUnits - 1, gs->grid.yUnits - 1);

	generateMaze(&gs->grid);
	clearviewport();
}


void drawGameScreen(GameScreen* gs) {
	drawGrid(&gs->grid);
	drawGameHud();

	//draw player
	drawGoal(&gs->goal);
	// draw goal
	drawPlayer(&gs->player);
}

void movePlayer(GameScreen* gs, int move) {
	switch (move)
	{
	case 0: // up
		if (!isWallInDir(&gs->grid, gs->player.gp.col, gs->player.gp.row, move)) {
			setCellPos(&gs->grid, &gs->player.gp, gs->player.gp.col, gs->player.gp.row - 1);
			setPlayerPos(&gs->player, &gs->grid, &gs->player.gp);
		}
		
		break;
	case 1: // right
		if (!isWallInDir(&gs->grid, gs->player.gp.col, gs->player.gp.row, move)) {
			setCellPos(&gs->grid, &gs->player.gp, gs->player.gp.col + 1, gs->player.gp.row);
			setPlayerPos(&gs->player, &gs->grid, &gs->player.gp);
		}
		break;
	case 2: // down
		if (!isWallInDir(&gs->grid, gs->player.gp.col, gs->player.gp.row, move)) {
			setCellPos(&gs->grid, &gs->player.gp, gs->player.gp.col, gs->player.gp.row + 1);
			setPlayerPos(&gs->player, &gs->grid, &gs->player.gp);
		}
		break;
	case 3: // left
		if (!isWallInDir(&gs->grid, gs->player.gp.col, gs->player.gp.row, move)) {
			setCellPos(&gs->grid, &gs->player.gp, gs->player.gp.col - 1, gs->player.gp.row);
			setPlayerPos(&gs->player, &gs->grid, &gs->player.gp);
		}
		break;
	}
}

bool checkGoal(GameScreen* gs) {
	if (gs->player.gp.col == gs->goal.gp.col && gs->player.gp.row == gs->goal.gp.row) {
		return true;
	}
	return false;
}