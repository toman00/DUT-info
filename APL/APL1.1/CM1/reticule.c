/* A chaque passage dans la boucle, on avance de 2 en largeur
et 4 en longueur  */


#include<stdio.h>
#include<stdlib.h>

    

int main(int argc, char * argv[]){
    
    printf("Choisissez le nombre de carrés : \n");


    int horizontal,vertical,taille,cote;
    scanf("%d",&taille);
    for(vertical=taille;vertical>0;vertical--){

        for(cote=(taille-vertical);cote>0;cote--){
            printf("| ");
        }
        printf("+");
        for(horizontal=(vertical*4)-2;horizontal>0;horizontal--){
            printf("-");
        }
        printf("+");
        for(cote=taille-vertical;cote>0;cote--){
            printf(" |");
        }
        printf("\n");
    }

    for(cote=0;cote<taille;cote++){
        printf("| ");
    }
    for(cote=0;cote<taille;cote++){
        printf(" |");
    }
    printf("\n");

    for(vertical=1;vertical<taille+1;vertical++){
        for(cote=0;cote<taille-vertical;cote++){
            printf("| ");
        }
        printf("+");
        for(horizontal=0;horizontal<(vertical*4)-2;horizontal++){
            printf("-");
        }
        printf("+");
        for(cote=0;cote<taille-vertical;cote++){
            printf(" |");
        }
        printf("\n");
    }

return EXIT_SUCCESS;
}  
