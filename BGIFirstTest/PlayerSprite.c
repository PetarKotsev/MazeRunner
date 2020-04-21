#include "CellPosition.h"
#include <stdlib.h>

typedef struct Player {
	CellPos gridPos;
	int playerSpriteVertacies[10];
} Player;

void setPlayer(Player * pl, int startCol, int startRow) {
	CellPos cp;
}

void drawPlayerSprite(Player * pl) {

}

void movePlayer(Player * pl, CellPos * cp)
{

}

CellPos* playerLocation(Player * pl) {
	return NULL
}