#include <stdio.h>

int main(void){
int entier=1234;
int entier2=4567;

printf("Entrez un entier : ");
scanf("%d", &entier);
printf("Entrez un second entier : ");
scanf("%d",&entier2);
printf("\nL'entier tapé est : %d et le second est : %d\n", entier, entier2);
}
