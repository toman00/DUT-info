/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
	/* Variables */
	struct stat target;
	int buffer;
	/* Si il n'y a pas 2 arguments */
	if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    stat(argv[1], buffer);



    /* Affichage de la taille */
	printf("File size: %3lld bytes\n", (long long) target.st_size);


	/* Valeur de retour */
	return EXIT_SUCCESS;
}