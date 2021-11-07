#include <stdio.h>
#include <stdlib.h>



int main(void) {

    int taille = 0;

	int i;



	printf("Entrez la longueur désirée (entre 1 et 9) : ");

	scanf("%d", &taille);

	

	for (i=0;(i<=taille)&&(taille>=1)&&(taille<10);++i){

		printf("|''''|''''");

	}

	printf("\n");

	for (i=0;i<=taille;++i){

		printf("%d         ",i);

	}

	printf("\n");





	 
    return EXIT_SUCCESS;
}


