// Inclusions
#include <stdio.h>
#include <stdlib.h>


// Création de la structure taille
typedef struct taille {
    int champ2;
    char champ1;
    char champ3;
}taille;

/* la taille de la structure change selon l'ordre dans lesquelles
les types sont placées, le type int (int>char en taille), est placé au dessus
et la structure prend moins de place dans sa totalité, par rapport
à si il avait été placé plus bas dans cette dernière */


int main(int argc, char** argv) {
    taille test = {};
    int taille;
    
    // Affichage de la taille du champ de la structure "taille"
    taille=sizeof(test);
    printf("Taille du champ : %d\n",taille);
    
    
    

    // Valeur de retour
    return EXIT_SUCCESS;
}

