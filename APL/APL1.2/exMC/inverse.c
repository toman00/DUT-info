#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv) {
    int valeur1=1,valeur2=2,valeur3=3,valeur4=4,valeur5=5;
    // Demande des entiers à l'user
    
    printf("Entier n°%d ", valeur1);
    scanf("%d", &valeur1);
    printf("\n");
        
    printf("Entier n°%d ", valeur2);
    scanf("%d", &valeur2);
    printf("\n");
        
    printf("Entier n°%d ", valeur3);
    scanf("%d", &valeur3);
    printf("\n");
       
    printf("Entier n°%d ", valeur4);
    scanf("%d", &valeur4);
    printf("\n");
       
    printf("Entier n°%d ", valeur5);
    scanf("%d", &valeur5);
    printf("\n");

    printf("%d, %d, %d, %d, %d\n",valeur5,valeur4,valeur3,valeur2,valeur1);
    
    
    // Valeur de retour
    return EXIT_SUCCESS;
}