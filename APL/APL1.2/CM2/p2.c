/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include "ma_sqrt.h"


/* Fonction : Demande à l'utilisateur de choisir 
 * quel racine il veut calculer. 
 * Ecrit dans un fichier le résultat
 * Retour : Aucun. */
void racineCalc (char* file) {
	/* Variables nécéssaires pour la racine */
	double a, res;
	int base, n;
	/* On ouvre le fichier en append afin d'y ajouter
	 * des résultats */
	FILE* flux = fopen("resultat.dat", "a");

	while ((a > 0) || !(base < 0) || !(n < 0)){
		res = 0;
		/* Demande à l'utilisateur */
		scanf(" %lf %d %d",&a, &base, &n);

		/* Calcule de la racine */
		res = ma_sqrt(a, base, n);

		/* On affiche la valeur qu'on voulait calculer */
		fwrite(a,sizeof(double),1,flux)
		/* On affiche le resultat */
		fwrite(res,sizeof(double),1,flux)
	}
	/* On ferme le fichier une fois l'écriture terminée */
	fclose(clux);
}


int main(int argc, char *argv[]) {

	/* On vérifie le nombre d'argument (min : 2) */
	if (argc > 1) {

		/* On appelle la fonction qui va demander
		 * à l'utilisateur de choisir ses valeurs 
		 * puis remplit la valeur à calculer et
		  * le résulta dans un fichier */
		racineCalc();
	}
	else {
		fprintf(stderr, "%d : Erreur, besoin d'un argument.", argv[0]);
		exit(1);
	}
	


	return EXIT_SUCCESS;
}