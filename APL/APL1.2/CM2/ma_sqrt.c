/* Inclusions */
#include <stdio.h>
#include <stdlib.h>


/* Fonction qui calcule la racine carré */
double ma_sqrt(double a, int base, int n) {
	double racine = base;

	while (n) {
		racine = (double) (racine + (a / racine))/2;
		--n;
	}
	printf("\n %lf \n", racine);
	return racine;
}