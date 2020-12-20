#include <stdio.h>
#include <string.h>
#include "myFuncs.h"

#define DECK_SIZE 52

// Blackjack Game
// @Author: xhico


void showMenu() {
	printf("# ---------------- #\n");
	printf("#  Blackjack Game  #\n");
	printf("# ---------------- #\n\n");
}


Player setupPlayers(char name[10], int points) {
	Player p;

	strcpy_s(p.name, sizeof(p.name), name);
	p.points = points;

	return p;
}


void showPlayers(Player p1, Player p2) {
	printf("Player 1\nName : %s\nPoints : %d\n\n", p1.name, p1.points);
	printf("Player 2\nName : %s\nPoints : %d\n", p2.name, p2.points);
}


void initDeck(Card deck[]) {
	int counter;
	int curr_value = 0; //For the obscure bug that occurs; the "skipping" of counter

	for (counter = 0; counter < DECK_SIZE; counter++) {
		deck[counter].name = counter % 13; //Gets card name
		if (deck[counter].name == JACK ||
			deck[counter].name == QUEEN ||
			deck[counter].name == KING)
			deck[counter].value = 10; //Gets card value for face cards
		else if (deck[counter].name == ACE)
			deck[counter].value = 11; //Gets card value for Ace
		else {
			deck[counter].value = curr_value % 9 + 2; //Gets card value for # cards
			curr_value++;
		}
	}
}


void shuffleDeck(Card deck[]) {
	Card temp; //Temporary value holder
	int curr_index; //Used to switch places with new_loc
	int new_loc; //New location of card in deck

	for (curr_index = 0; curr_index < DECK_SIZE; curr_index++) {
		new_loc = rand() % DECK_SIZE; //Picks subscript from DECK_SIZE - 1 for array
		temp = deck[curr_index]; //Type CARD temp gets card from 0 - 51
		deck[curr_index] = deck[new_loc]; //Current card gets new location
		deck[new_loc] = temp; //New location gets temp
	}
}


int main() {
	showMenu();

	Player p1 = setupPlayers("Dealer", 0);
	Player p2 = setupPlayers("xhico", 0);

	showPlayers(p1, p2);
	printf("\n\n");

	Card deck[DECK_SIZE];
	initDeck(deck);
	shuffleDeck(deck);

	return 0;
}
