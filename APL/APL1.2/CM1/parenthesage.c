/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	/* Variables */
	int taille;
	/* Stockage des ( ) */
	char* tab;

	/* pointeur remplissage de tab et pointeur d'argv[1] */
	int pointeur = 0;
	int pointeurtab = 0;
	/* Nb de parenthèse ouvrante et formantes */
	int oponedpar= 0, closedpar = 0;
	tab = malloc(strlen(argv[1])*sizeof(char));




	/* Si il n'y pas une chaîne de char */
	if (argc < 1) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(1);
	}

	for (taille = strlen(argv[1]); taille > 0 ; --taille) {
		/* Si l'on détecte une parenthèse () */
		if (argv[1][pointeur]=='(')	{
			tab[pointeurtab] = '(';
			printf("%c",tab[pointeurtab]);
			++pointeurtab;
		}

		if (argv[1][pointeur]==')')	{
			tab[pointeurtab] = ')';
			printf("%c",tab[pointeurtab]);
			++pointeurtab;
		}
		++pointeur;
	}

	if (oponedpar != closedpar)	{
		printf("NOK");
	}
	else printf("OK");
	printf("\n");

	free(tab);
	


	/* Valeur de retour */
	return EXIT_SUCCESS;
	
}