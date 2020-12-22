#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECK_SIZE 52;



int main() {
	printf("# ---------------- #\n");
	printf("# Blackjack C Game #\n");
	printf("# Author: xhico    #\n");
	printf("# ---------------- #\n\n");

	char pName[6];
	int bankroll;


	printf("Player Name: ");
	scanf_s("%s", pName, sizeof(pName));

	printf("Insert bankroll: ");
	scanf_s("%d", &bankroll);

	printf("\nPlayer %s with %d\n", pName, bankroll);


	return 0;
}