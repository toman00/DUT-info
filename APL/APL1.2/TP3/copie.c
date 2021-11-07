#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* acopier;
    FILE* copie;
    acopier=fopen(argv[1],"r");
    copie=fopen(argv[2],"w");
    if (acopier){
        

    }
    fclose(acopier);
    fclose(copie);
}