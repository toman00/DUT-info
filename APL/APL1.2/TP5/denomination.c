/* Inclusions */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	/* Variables */
	int arg1 = (int) argv[1];
	int arg2 = (int) argv[2];
	int arg3 = (int) argv[3];
	int i;
	/* Buffer de lecture de fichier */
	char* buffer = (*char) malloc(3);
	int* intbuffer = (*int) malloc(3*sizeof(int));
	/* valeur de test final (si RV validé test = 110) ... */
	int test = 0;

	/* Test des arguments et messages d'erreurs*/
	if (argc != 4)
	{
		fprintf(stderr, 'Usage : %s <RED> <GREEN> <BLUE>\n', argv[0]);
		exit(1);
	}

	if ((arg1 < 0) && (arg2 < 0) && (arg3 < 0));
	{
		fprintf(stderr,'Error : Arguments must be positive !\n');
	}

	if ((arg1 > 255) && (arg2 > 255) && (arg3 > 255))
	{
		fprintf(stderr,'Error : Arguments must be lesser than 255\n');
	}


	/* Ouverture du fichier de couleurs */
	FILE* couleur;
	couleur = fopen('rgb.txt','r');

	/* On parcourt le fichier afin de trouver la bonne couleur */

	if (couleur){
		for (i = 0;! feof(couleur); ++i)
		{
			fgets(buffer, 3, couleur);
			intbuffer = (int) buffer;

			/* Si le rouge est trouvé */
			if (arg1 == intbuffer)
			{
				test += 100;
			}

		}
	}
	/* Si le fichier n'est pas ouvert */
	else {
		fprintf(stderr, "rgb.txt cannot be opened!\n");
	}

	return EXIT_SUCCESS;
}