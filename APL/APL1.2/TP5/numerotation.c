/* Inclusions */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 255


int main(int argc, char *argv[]) {
	/* Variables */
	int i;
	char* buffer = (char *) malloc(MAX_LENGTH);



	/* Si le premier argument est manquant */
	if (argc != 2)
	{
		fprintf(stderr,"Error, usage : %s <path-to-file>\n", argv[0]);
		exit(1);
	}


	/* Recuperation chemin du fichier et ouverture du fichier */
	FILE* text;
	text = fopen(argv[1],"r");

	/* Boucle pour lire le fichier */
	if (text)
	{
		for (i = 1; ! feof(text); ++i)
		{
			fgets(buffer,MAX_LENGTH,text);
			printf("%d : %s",i ,buffer);
		}
	printf("\n");
	}


	free(buffer);
	fclose(text);

	return EXIT_SUCCESS;
}