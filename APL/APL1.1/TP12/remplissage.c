#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){

	int taille=9;
	int tab[taille];
	int i;
	srand(time(NULL));



	for (i=0; i<=9;++i){
		tab[i]=(rand()%101)-50;
		printf("%d\t",tab[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;

}