#pragma once
#include <stdio.h>
#include <malloc.h>

/**********************
*	Work in progress
**********************/


typedef struct PlayerScore {
	char name[11];
	int	 time;
}PlayerScore;

static int readSize() {
	int i = 0;
	FILE * ptr;
	fopen_s(&ptr, "scores.txt", "r");
	if (ptr) {
		char ch;
		while (ch = fgetc(ptr) != EOF) {
			if (ch == ',') {
				i++;
			}
		}
	}
	return i;
}

bool readScores(char** n, int* scores) {
	int size = readSize();
	FILE * ptr;
	fopen_s(&ptr, "scores.txt", "r");
	char buff[80];
	int buffTop = 0, i = 0;
	char ch;
	n = (char**)calloc(size, sizeof(char*));

	if (ptr) {
		while ((ch = fgetc(ptr)) != EOF) {
			if (ch == ',') {
				n[i] = (char*)malloc((buffTop+1) * sizeof(ch));
				for (int j = 0; j < buffTop; j++) {
					n[i][j] = buff[j];
				}
				printf("%s --> %s \n", buff, n[i]);
				buffTop = 0;
				i++;
				continue;
			}
			buff[buffTop] = ch;
			buffTop++;
		}
	}
	fclose(ptr);
}

bool putScores (char * scoreText) {
	FILE * ptr;
	fopen_s(&ptr, "scores.txt", "a+");
	fputs(scoreText, ptr);
	fclose(ptr);
}