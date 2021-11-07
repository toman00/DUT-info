#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){


	int tentative;
	int nbtent;
	srand(time(NULL));
	int sol = rand()%101;

	printf("***\tDevinnete\t***\n\n");
	
	
	for (nbtent=0;nbtent<=5&&sol!=tentative;nbtent=nbtent+1){
		printf("Rentrez une valeur : ");
		scanf("%d",&tentative);

		if (tentative<0||tentative>100){
			printf("Le nombre doit être compris entre 0 et 100, réessayer ...\n");
			nbtent=nbtent-1;
		}
		if (tentative<sol){
			printf("C'est +.\n");
		}
		if (tentative>sol){
			printf("C'est -.\n");
		}
		if (tentative==sol){
			printf("Bravo, vous l'avez trouvé !\n");
		}
	}
	if (nbtent>5){
		printf("Nombre de tentative épuisé, le résultat était %d, on recommence !\n",sol);
	}
}