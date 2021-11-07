#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char count=27,i;
    char mdp[count];
    char* passwd=mdp;
    char entry;
    /*mdp de 26 charactères maximum ! */
    /* strchr ascii table between 33,126 (compris) 
    utiliser strcat*/
    printf("Tapez votre mot de passe (26 charactères au maximum) :\n");
    entry = getchar();
    //strcat(char *entry, const char *passwd);
    printf("%c", entry);
    
    
    





}