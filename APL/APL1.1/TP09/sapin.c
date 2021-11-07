#include <stdio.h>
#include <stdlib.h>

int main(void){

	int hauteur=0;
	int etoiles=0;
	int etages=0;
	int i=0;


	printf("Hauteur ? ");
	scanf("%u",&hauteur);


	for (etages=0;etages<hauteur;++etages){
		for (i=hauteur-etages;i!=0;--i){
			printf(" ");
			for (etoiles=etages;etoiles>0;--etoiles){
				printf("*");
			}
		}
		printf("\n");
	}



}
