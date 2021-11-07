#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){

	int taille=9;
	int tab[taille];
	int i;
	srand(time(NULL));
	int max=0;




	for (i=0; i<=9;++i){
		tab[i]=(rand()%101)-50;
		printf("%d\t",tab[i]);
		if (tab[i]>tab[max]){
			max=i;
		}
	}
	printf("\n");

	printf("%d\n",max);

	return EXIT_SUCCESS;

}