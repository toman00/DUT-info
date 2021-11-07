#include <stdio.h>
#include "matrix.h"

int main(int argc, char** argv) {
    int taille;
    matrix sum;

    printf("Rentrez la taille de la matrice : ");
    scanf("%d",&taille);



    matrix m = identity_matrix(taille);
    matrix n = identity_matrix(taille);
    print_matrix(m);
    printf("multiplication des 2 matrices : \n");
    sum = multiply_matrix(m, n);
    print_matrix(sum);
}