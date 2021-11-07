#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

	int hauteur=0;
	int etoiles=0;
	int i,j;

    printf("Hauteur ?");
    scanf("%d",&hauteur);


    /* Carré */ 
    for (i=0;i<hauteur;++i){
        for (j=0;j<hauteur;++j){
            if (( i==0) || (i == hauteur -1 ) || ((j==0) || (j==hauteur-1)))printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    


}