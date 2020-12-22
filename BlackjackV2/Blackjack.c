#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECK_SIZE 52;

int main() {

	char pName[6];
	printf("Player Name: ");
	scanf_s("%s", pName, sizeof(pName));

	printf("\nPlayer's Name: %s", pName);


	return 0;
}