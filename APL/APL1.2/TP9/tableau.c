/* Inclusions */
#include <stdio.h>
#include <stdlib.h>

/* Fonction recursive qui affiche le tableau 
 * en entier*/

void printTab(double* n) {
	if (n) {
		printf("%f\n", *n);
	}
}

int main(int argc, char *argv[]) {
	double test[5];
	test[0] = 6.0;
	test[1] = 5.4;
	test[2] = 4.3;
	printTab(test);

	return EXIT_SUCCESS;
}