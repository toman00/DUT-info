#include <stdio.h>
#include <stdlib.h>

int main(void){

    unsigned int taille=2;
    unsigned int abscisse=0;
    unsigned int ordonnee=0;

    printf("  X  |");
    for (abscisse=0;abscisse<=taille;++abscisse){
        printf("%4u",abscisse);  
  
    }
    printf("\n-----+");
    for(abscisse=0; abscisse<=taille;++abscisse){
        printf("----");
    }
    for (ordonnee=0;ordonnee<=taille;++ordonnee){
         printf("\n%3u  |",ordonnee);
        for (abscisse=0;abscisse<=taille;++abscisse){
            printf("%4u",abscisse*ordonnee);
        }
    }
}