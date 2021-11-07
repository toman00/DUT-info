/* Inclusions */
#include <stdio.h>
#include <stdlib.h>

/* Fontion récursive qui calcule le n-ieme terme
 * de la suite de Fibonacci */
unsigned fibo (unsigned n) {
	if (n>=2) {
		return fibo(n-2)+fibo(n-1);
	}
	else {
		if (n == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
}

void printFibo (unsigned m) {
	printf("%d",fibo(m));
}

int main(int argc, char *argv[]) {
	unsigned valeur = 15;
	printFibo(valeur);


	return EXIT_SUCCESS;
}