#pragma once
#include "grid.h"
#include "MazeGenerator.h"
#include "WelcomeScreen.h"
#include "GameScreen.h"


/*
*	Game state variables
*/
enum gameState {
	WELCOME_SCREEN,
	START_COUNTDOWN,
	LEADERBOARD,
	INITIALIZE_GAME_SCREEN_LEVEL_1,
	GAME_SCREEN_LEVEL_1,
	GENETARE_MAZE,
	RUN,
	POUSE,
	QUIT
};

enum gameState globalState = INITIALIZE_GAME_SCREEN_LEVEL_1;
/*	Read state	*/

void readKeyboard();
void waitForKeyPress();

void readState() {
	switch (globalState)
	{
	case WELCOME_SCREEN:
		drawWelcomeScreen();
		readKeyboard();
		break;
	case START_COUNTDOWN:
		break;
	case LEADERBOARD:
		//drawLeaderboard();
		break;
	case INITIALIZE_GAME_SCREEN_LEVEL_1: {
		newGameScreen(20, 60, 20, 2, 2, 33, 20);
		globalState = GAME_SCREEN_LEVEL_1;
	}
	case GAME_SCREEN_LEVEL_1:
		drawGameScreen();
		readKeyboard();
		break;
	case GENETARE_MAZE:
		newCellGrid(&grid, 20, 60, 20, 2, 2, 33, 20);
		generateMaze(&grid);
		globalState = RUN;
		break;
	case RUN:
		//drawGrid();
		waitForKeyPress();
		break;
	case POUSE:
		break;
	case QUIT:
		exit(0);
		break;
	default:
		break;
	}
}


/*
*	Move direction
*/

enum moveDir {
	UP,
	RIGHT,
	DOWN,
	LEFT,
	NONE
};

static enum moveDir move = NONE;

void keyboardHendler() {
	int c = readkey();
	printf("%d\n", c);
	switch (c)
	{
	case 119: // pressed w or W
	case 87:	move = UP;
		break;
	case 100: // pressed d or D
	case 68:	move = RIGHT;
		break;
	case 97: // pressed a or A
	case 65:	move = LEFT;
		break;
	case 115: // pressed s ot S
	case 83:	move = DOWN;
		break;
	case 32: // pressed Space
		if (globalState == WELCOME_SCREEN) {
			globalState = INITIALIZE_GAME_SCREEN_LEVEL_1;
		}
		else if (globalState == POUSE) {
			globalState = RUN;
		}
		else if (globalState == RUN) {
			globalState = POUSE;
		}
		break;
	case 27: // pressed Esc
		globalState = QUIT;
	default:
		break;
	}
}

void readKeyboard() {
	if (anykeypressed()) {
		keyboardHendler();
	}
}

void waitForKeyPress() {
	keyboardHendler();
}

enum moveDir * getMove() {
	return &move;
}