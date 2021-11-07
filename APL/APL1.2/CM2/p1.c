/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include "ma_sqrt.h"


/* Fonction : Demande à l'utilisateur de choisir 
 * quel racine il veut calculer. 
 * Retour : Aucun. */
void racineCalc (void) {
	/* Variables nécéssaires pour la racine */
	double a, res;
	int base, n;

	while ((a > 0) || !(base < 0) || !(n < 0)){
		res = 0;
		/* Demande à l'utilisateur */
		scanf(" %lf %d %d",&a, &base, &n);


		res = ma_sqrt(a, base, n);
		/* On affiche le resultat */
		printf("Racine carree de %lf = %0.15lf\n", a, res);
	}
}

int main(int argc, char *argv[]) {

	/* On appelle la fonction qui va demander
	 * à l'utilisateur de choisir ses valeurs */
	racineCalc();
	


	return EXIT_SUCCESS;
}