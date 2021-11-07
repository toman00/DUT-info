/*Entrez votre taille : 1.57
1.57-5*0.3072=0.034  (5 pieds)
0.034 - 0.0256=0.0084 (1 pouce)
on arrondie à l'entier le + proche, ici 0.


Entrez votre taille : 1.75
1.75-5*0.3072=0.214 (5 pieds)
0.214-8*0.0256=0.0092 (8 pouces)
On arrondie à 0.

Entrez votre taille : 0.40
0.40-1*0.3072=0.0928 (1 pied)
0.0928-3*0.0256=0.016 (3 pouces)
On arrondie à 0.



1 pied:12*2.56=30.72cm soit 	0.3072m
1 pouce: 2.56cm  soit 0.0256m */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PIED 0.3072
#define POUCE 0.0256

int main(void) {
	double taille=0;
	long int poucecount = 0;
	long int piedcount = 0;

	printf("Entrez votre taille : ");
	scanf("%lf",&taille);
	printf("\n");
	for (piedcount=0;PIED<taille;++piedcount){
		taille=taille-PIED;
	}

	for (poucecount=0;POUCE<taille;++poucecount){
		taille=taille-POUCE;
	}
    long int lround(double taille);
	
	if (piedcount>0){
		if (piedcount>1){
			printf("%ld pieds",piedcount);
		}
		else printf("%ld pied", piedcount);
		if (poucecount>0)printf(" et ");
	}
	if (poucecount>0){
		if (poucecount>1){
			printf("%ld pouces",poucecount);
			}
		else printf("%ld pouce",poucecount);
	}
	

	printf("\n");
	
	


return EXIT_SUCCESS;
}