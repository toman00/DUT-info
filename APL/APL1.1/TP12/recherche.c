#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){

	int taille=9;
	int tab[taille];
	int i;
	srand(time(NULL));
	int search=-1;

	for (i=0; i<=9;++i){
		tab[i]=(rand()%101)-50;
		printf("%d\t",tab[i]);
	}
	printf("\n");
	printf("Entrez une valeur à rechercher dans le tableau : ");
	scanf("%d",&search);
	for (i=0;i<=9;++i){
		if (search==tab[i]){
			printf("%d\n",i);
			break;
		}

	}

	return EXIT_SUCCESS;

}