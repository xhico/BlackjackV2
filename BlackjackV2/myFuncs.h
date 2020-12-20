#pragma once


typedef enum {
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING,
	ACE
} CardName;


typedef struct {
	CardName name;
	int value;
} Card;


typedef struct {
	char name[10];
	int points;
} Player;


void showMenu();
Player setupPlayers(char name[10], int points);
