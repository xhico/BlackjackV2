#pragma once

typedef enum {
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING,
	ACE
} CARD_NAME;

typedef struct {
	CARD_NAME name;
	int value;
} CARD;


void initDeck(CARD deck[]);
void shuffleDeck(CARD deck[]);
void printCard(CARD card);
int dealCard(CARD deck[], int* curr);
int playerTurn(CARD deck[], int* player_value, int* current_card);
int dealerTurn(CARD deck[], int* dealer_value, int* current_card);
void handleEndRound(int player_value, int dealer_value, int* bankroll, int bet);
void handleBeginRound(CARD deck[], int* player_value, int* dealer_value, int* current_card);
int getBet(int bankroll);
int keepOnGoing(int bankroll);










