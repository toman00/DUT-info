/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
typedef pile pile;
struct pile {
	int caractere;
	pile* suivant;
}

void push(pile* pPile) {
	int i;
	if (pPile) {
		for (i = *pPile; pPile->suivant != NULL; pPile = pPile->suivant) {
			
		}
	}
}


int main(int argc, char *argv[]) {



	return EXIT_SUCCESS;
}