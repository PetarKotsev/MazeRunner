#pragma once
#include "grid.h"
#include "MazeGenerator.h"
#include "WelcomeScreen.h"
#include "LoadingScreen.h"
#include "GameScreen.h"
#include "CountdownScreen.h"


/*
*	Game state variables
*/
enum gameState {
	RUN,
	RUN_N_WAIT,
	POUSE,
	QUIT,
};

enum screenView {
	WELCOME_SCREEN,
	INITIALIZE_GAME_SCREEN_LEVEL_1,
	GAME_SCREEN,
	LEADERBOARD,
	WIN_SCREEN,
	POUSE_SCREEN,
	TEST_LOADING_SCREEN,
	TEST_GAME_SCREEN
};

enum gameState globalState = RUN;
enum screenView currentPage = WELCOME_SCREEN;
/*	Read state	*/

void readKeyboard();
void waitForKeyPress();


GameScreen gameScreen;

void readScreen() {
	switch (currentPage)
	{
	case WELCOME_SCREEN:
		drawWelcomeScreen();
		break;
	case LEADERBOARD:
		// ToDo
		break;
	case INITIALIZE_GAME_SCREEN_LEVEL_1:
		newGameScreen(&gameScreen, 20, 20, 20, 0, 0, 33, 33);
		drawCountdownScreen();
		currentPage = GAME_SCREEN;
		break;
	case GAME_SCREEN:
		drawGameScreen(&gameScreen);
		break;
	case WIN_SCREEN:
		break;
	case POUSE_SCREEN:
		// ToDo
		break;
	case TEST_LOADING_SCREEN:
		drawLoadingScreen();
		break;
	case TEST_GAME_SCREEN:
		newGameScreen(&gameScreen, 20, 20, 20, 0, 0, 33, 33);
		drawCountdownScreen();
		drawGameScreen(&gameScreen);
		waitForKeyPress();
		break;
	default:
		break;
	}
}

void readState() {
	switch (globalState)
	{
	case RUN:
		readScreen();
		readKeyboard();
		delay(50);
		break;
	case RUN_N_WAIT:
		readScreen();
		break;
	case POUSE:
		readScreen();
		currentPage = POUSE_SCREEN;
		readKeyboard();
		delay(100);
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
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
	NONE = 4
};

static enum moveDir move = NONE;

void keyboardHendler() {
	int c = readkey();
	
	
	if (globalState == RUN) {
		if (currentPage == WELCOME_SCREEN) {
			switch (c)
			{
			case 32: // Space
				currentPage = INITIALIZE_GAME_SCREEN_LEVEL_1;
				break;
			}
		}
		else if (currentPage == GAME_SCREEN) {
			switch (c)
			{
			case 119: // pressed w or W
			case 87:	
				move = UP;
				movePlayer(&gameScreen, move);
				checkGoal(&gameScreen);
				break;
			case 100: // pressed d or D
			case 68:	
				move = RIGHT;
				movePlayer(&gameScreen, move);
				checkGoal(&gameScreen);
				break;
			case 97: // pressed a or A
			case 65:	
				move = LEFT;
				movePlayer(&gameScreen, move);
				checkGoal(&gameScreen);

				break;
			case 115: // pressed s ot S
			case 83:	
				move = DOWN;
				movePlayer(&gameScreen, move);
				if (checkGoal(&gameScreen)) {
					currentPage = WIN_SCREEN;
				}
				break;
			case 32: // Space
				globalState = POUSE;
				currentPage = POUSE_SCREEN;
				break;
			}
		}
	}
	else if (globalState == POUSE){
		if (currentPage == POUSE_SCREEN) {
			switch (c)
			{
			case 32: // Space
				globalState = RUN;
				currentPage = GAME_SCREEN;
				break;
			case 27: // ESC
				globalState = QUIT;
			default:
				break;
			}
		}
	}
	else if (globalState == QUIT) {

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