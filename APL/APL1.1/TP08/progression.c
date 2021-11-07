#include <stdio.h>
#include <stdlib.h>

int main (void){

    int u0=0;
    int u1=1;
    int un=0;
    int temp=0;
    unsigned int i=0;

    printf("Entrez un entier : ");
    scanf("%d", &un);
    
    do {
        temp=u0;
        u0=u1+u0;
        u1=temp;
        ++i;
    } while(i<un);
    printf("\nle nieme terme de la suite est : %d.",u0);



}