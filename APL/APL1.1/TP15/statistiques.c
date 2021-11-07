#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char string[201]={0};
    char* character;
    character = string;

    if (argc==0)printf("!! Besoin d'un argument !! (une seule chaîne de caractère)");
    if (argc > 1)printf("Seulement le 1er mot sera lu :\n");

    printf("%s",*character);






}
