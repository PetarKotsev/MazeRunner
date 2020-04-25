#pragma once
#include "grid.h"
#include "MazeGenerator.h"
#include "WelcomeScreen.h"
#include "LoadingScreen.h"
#include "GameScreen.h"
#include "CountdownScreen.h"
#include "WinScreen.h"
#include "PauseScreen.h"

/*
*	Game state variables
*/
enum gameState {
	RUN,
	RUN_N_WAIT,
	POUSE,
	QUIT,
};

/*
*	Screen variables
*/
enum screenView {
	WELCOME_SCREEN,
	INITIALIZE_GAME_SCREEN_LEVEL_1,
	GAME_SCREEN,
	INITIALIZE_WIN_SCREEN,
	WIN_SCREEN,
	PAUSE_SCREEN,
};

/*
*	Move direction
*/
enum moveDir {
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
	NONE = 4
};

/* Game Frame structure and constructor method*/
typedef struct GameFrame {
	enum moveDir move;
	enum gameState frameState;
	enum screenView currentPage;
	GameScreen gameScreen;
	WinScreen ws;
} GameFrame;

GameFrame* newGameFrame(GameFrame* gf) {
	gf->move = NONE;
	gf->frameState = RUN;
	gf->currentPage = WELCOME_SCREEN;
}

/*	Function initializations  */
static void readKeyboard(GameFrame* gf);
static void waitForKeyPress(GameFrame* gf);
static void readScreenState(GameFrame* gf);
static void keyboardHendler(GameFrame* gf);
void readState(GameFrame* gf);


/*  Function definitions  */
static void readScreenState(GameFrame* gf) {
	switch (gf->currentPage)
	{
	case WELCOME_SCREEN:
		drawWelcomeScreen();
		gf->frameState = RUN;
		break;
	case INITIALIZE_GAME_SCREEN_LEVEL_1:
		newGameScreen(&gf->gameScreen, 20, 20, 20, 0, 0, 33, 33);
		drawCountdownScreen();
		startGameScreenTimer(&gf->gameScreen);
		gf->currentPage = GAME_SCREEN;
		break;
	case GAME_SCREEN:
		drawGameScreen(&gf->gameScreen);
		gf->frameState = RUN_N_WAIT;
		break;
	case INITIALIZE_WIN_SCREEN:
		printf("%d", gf->gameScreen.endTime);
		newWinScreen(&gf->ws, gf->gameScreen.endTime);
		gf->currentPage = WIN_SCREEN;
		break;
	case WIN_SCREEN:
		drawWinScreen(&gf->ws);
		gf->frameState = RUN;
		break;
	case PAUSE_SCREEN:
		drawPouseScreen();
		break;
	}
}

void readState(GameFrame* gf) {
	switch (gf->frameState)
	{
	case RUN:
		readKeyboard(gf);
		readScreenState(gf);
		delay(50);
		break;
	case RUN_N_WAIT:
		waitForKeyPress(gf);
		readScreenState(gf);
		break;
	case POUSE:
		readScreenState(gf);
		gf->currentPage = PAUSE_SCREEN;
		readKeyboard(gf);
		delay(100);
		break;
	case QUIT:
		exit(0);
		break;
	default:
		break;
	}
}

static void keyboardHendler(GameFrame* gf) {
	int c = readkey();
	
	if (gf->frameState == RUN) {
		if (gf->currentPage == WELCOME_SCREEN) {
			switch (c)
			{
			case 32: // Space
				gf->currentPage = INITIALIZE_GAME_SCREEN_LEVEL_1;
				break;
			}
		}
		if (gf->currentPage == WIN_SCREEN) {
			switch (c)
			{
			case 32: // Space
				gf->currentPage = WELCOME_SCREEN;
				break;
			case 27: 
				gf->frameState = QUIT;
				gf->currentPage = QUIT;
				break;
			}
		}
	}
	else if (gf->frameState == RUN_N_WAIT) {
		if (gf->currentPage == GAME_SCREEN) {
			switch (c)
			{
			case 119: // pressed w or W
			case 87:
				gf->move = UP;
				movePlayer(&gf->gameScreen, gf->move);
				if (checkGoal(&gf->gameScreen)) {
					gf->frameState = RUN;
					gf->currentPage = INITIALIZE_WIN_SCREEN;
				}
				break;
			case 100: // pressed d or D
			case 68:
				gf->move = RIGHT;
				movePlayer(&gf->gameScreen, gf->move);
				if (checkGoal(&gf->gameScreen)) {
					gf->frameState = RUN;
					gf->currentPage = INITIALIZE_WIN_SCREEN;
				}
				break;
			case 97: // pressed a or A
			case 65:
				gf->move = LEFT;
				movePlayer(&gf->gameScreen, gf->move);
				if (checkGoal(&gf->gameScreen)) {
					gf->frameState = RUN;
					gf->currentPage = INITIALIZE_WIN_SCREEN;
				}

				break;
			case 115: // pressed s ot S
			case 83:
				gf->move = DOWN;
				movePlayer(&gf->gameScreen, gf->move);
				if (checkGoal(&gf->gameScreen)) {
					gf->frameState = RUN;
					gf->currentPage = INITIALIZE_WIN_SCREEN;
				}
				break;
			case 32: // Space
				gf->frameState = POUSE;
				gf->currentPage = PAUSE_SCREEN;
				break;
			}
		}
	}
	else if (gf->frameState == POUSE){
		if (gf->currentPage == PAUSE_SCREEN) {
			switch (c)
			{
			case 32: // Space
				gf->frameState = RUN;
				gf->currentPage = GAME_SCREEN;
				break;
			case 27: // ESC
				gf->frameState = QUIT;
				gf->currentPage = QUIT;
			default:
				break;
			}
		}
	}
	else if (gf->frameState == QUIT) {

	}
}

void readKeyboard(GameFrame* gf) {
	for (int i = 0; i < 5; i++) {
		if (anykeypressed()) {
			keyboardHendler(gf);
			break;
		}
		delay(10);
	}
}

void waitForKeyPress(GameFrame* gf) {
	for (int i = 0; i < 100; i++) {
		if (anykeypressed()) {
			keyboardHendler(gf);
			break;
		}
		delay(10);
	}
}
