#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define DECK_SIZE	52
#define NAME_LEN	10


typedef enum {
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING,
	ACE
} CARD_NAME;

typedef struct {
	CARD_NAME name;
	int value;
} CARD;


void showHeader() {
	printf("# ---------------- #\n");
	printf("# Blackjack C Game #\n");
	printf("# Author: xhico    #\n");
	printf("# ---------------- #\n\n");
}


void setPlayer(char pName[], int pNameLen, int* bankroll) {
	printf("Insert name: ");
	scanf_s("%s", pName, pNameLen);

	printf("Insert bankroll: ");
	scanf_s("%d", bankroll);
}


void initDeck(CARD deck[]) {
	for (int i = 0; i < DECK_SIZE; i++) {
		deck[i].name = i % 13;

		if (deck[i].name == JACK ||
			deck[i].name == QUEEN ||
			deck[i].name == KING) {
			deck[i].value = 10;
		} else if (deck[i].name == ACE) {
			deck[i].value = 11;
		} else {
			deck[i].value = i % 9 + 2;
		}
	}
}


void suffleDeck(CARD deck[]) {
	CARD temp;
	int new_loc;

	for (int i = 0; i < DECK_SIZE; i++) {
		new_loc = rand() % DECK_SIZE;
		temp = deck[i];
		deck[i] = deck[new_loc];
		deck[new_loc] = temp;
	}
}


int getBet(int bankroll) {
	int tmp;

	printf("Current bankroll: %d\n", bankroll);
	printf("Insert a value between %d and %d\n", 0, bankroll);

	do {
		printf("Place your bet: ");
		scanf_s("%d", &tmp);
	} while (tmp > bankroll);

	return tmp;
}







int main() {

	char pName[NAME_LEN];
	int bankroll;
	CARD deck[DECK_SIZE];
	int bet;

	showHeader();

	setPlayer(pName, sizeof(pName), &bankroll);
	printf("Player Name is %s with Bankroll %d\n\n", pName, bankroll);

	bet = getBet(bankroll);
	printf("Current Bet: %d\n\n", bet);

	printf("Initializing deck...\n");
	initDeck(deck);

	printf("Shuffling deck...\n");
	suffleDeck(deck);


	return 0;
}