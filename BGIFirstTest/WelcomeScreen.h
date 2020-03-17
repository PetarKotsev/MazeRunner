#pragma once
static int __counter = -200;
static bool animationFlag = true;

void drawWelcomeScreen() {
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 70 + (__counter / 50 % 5));
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setcolor(rgb(141, 110, 99));
	outtextxy(midx + 2, midy - 148, "THE MAZE RUNNER");
	setcolor(rgb(255, 167, 38));
	outtextxy(midx, midy - 150, "THE MAZE RUNNER");



	settextstyle(COMPLEX_FONT, HORIZ_DIR, 10);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setcolor(rgb(130,130,130));
	outtextxy(midx, midy - 30, "TAB         -   Leaderboard");
	outtextxy(midx, midy -  0, "Space       -    Pause/Play");
	outtextxy(midx, midy + 30, "Arrows/WASD -          Move");
	outtextxy(midx, midy + 60, "ESC         -     Exit game");
	setcolor(rgb((200.0/255.0)*abs(__counter) + 50, (200.0 / 255.0)*(abs(__counter)) + 50, (200.0 / 255.0)*(abs(__counter)) + 50));
	__counter += 20;
	if (__counter >= 200) {
		__counter = -200;
	}
	outtextxy(midx, midy + 120, "( Press SPACE to start the game. )");
	delay(50);
}

