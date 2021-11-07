#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    double reel = 0;
    int entiere = 0;
    double dixieme = 0;

    printf("Entrez un réel : ");
    scanf("%Lf",&reel);
    printf("\n");
    
    entiere = trunc(reel);
    dixieme = reel-trunc(reel);
    dixieme = (char) dixieme;
    while (entiere>10){
        entiere=entiere-10;
    }
    entiere=abs(entiere);
    printf("chiffre des unités :    %hhi\n",entiere);
    printf("chiffre des dixièmes :  %hhi\n",dixieme);
}