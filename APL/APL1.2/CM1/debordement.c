/* Inclusions */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /*variables */

  unsigned long int l; /* Résultat de la factorielle n! */
  int n = 1; /* n de départ */
  int nfact; /* valeur utilisé */
  /* Variable de test */
  unsigned long int ltest = 1;
  int ntest;
  /* Boucle de pour aller au débordement
  de la factorielle */
  
	while (ltest) {
	  n++;
	  nfact = n;
	  l = 1;

	  /* Calcul et test de la factorielle */
	  while (nfact>0){
	  	l = l * nfact;
	  	ltest = l / 2;
	  	ntest = nfact / 2;
	  	nfact--;
	  	/* Calcul des valeurs de test /2 pour éviter un dépassement */
	  	while (ntest > 0){
	  	  	ltest = ltest * ntest;
	  	  	ntest--;
	  	}

	  }
	  /* test du résultat */
	  if (ltest * 2 != l){
	  	ltest = 0;
	  	}
	}
  	
  
 
  printf("valeur de n = %d, valeur de %d! = %lu\n", n, n, l);
  
  /* valeur de retour */
  return EXIT_SUCCESS;


}