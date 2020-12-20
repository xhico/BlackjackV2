#include <stdio.h>
#include <string.h>
#include "myFuncs.h"

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


int main() {
	showMenu();

	Player p1 = setupPlayers("Dealer", 0);
	Player p2 = setupPlayers("xhico", 0);

	showPlayers(p1, p2);


	return 0;
}
