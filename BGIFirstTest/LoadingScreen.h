#pragma once
#include "GameHud.h"

void drawLoadingScreen() {
	drawGameHud();

	//settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(0, 0, 25);

	switch (getGlobalCounter() / 100 % 4)
	{
	case 0: outtextxy(330, 330, "Loading    ");
			break;
	case 1: outtextxy(330, 330, "Loading .  ");
		break;
	case 2: outtextxy(330, 330, "Loading .. ");
			break;
	case 3: outtextxy(330, 330, "Loading ...");
			break;
	default:
		break;
	}
}