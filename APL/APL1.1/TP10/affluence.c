#include <stdio.h>
#include <stdlib.h>

int main(void){

unsigned int lu=0U;
unsigned int ma=0U;
unsigned int me=0U;
unsigned int je=0U;
unsigned int ve=0U;
unsigned long long int moyenne=0ULL;

printf("Entrez le nombre de visiteur pour chaque jour de la semaine : ");
printf("\nLundi :");
scanf("%u",&lu);
printf("\nMardi :");
scanf("%u",&ma);
printf("\nMercredi :");
scanf("%u",&me);
printf("\nJeudi :");
scanf("%u",&je);
printf("\nVendredi:");
scanf("%u",&ve);


moyenne=((lu+ma+me+je+ve)/5);
printf("Moyenne visiteurs : %llu par jour.\n",moyenne);

return EXIT_SUCCESS; 

}