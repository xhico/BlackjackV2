#pragma once

typedef struct Players {
	char name[10];
	int points;
} Player;


void showMenu();
Player setupPlayers(char name[10], int points);
