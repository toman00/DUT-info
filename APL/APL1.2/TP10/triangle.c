/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

void DessinerTriangle(int x,int y,int taille){
	
}

int main(int argc, char *argv[]) {
	/* Initialisation de la fenêtre */
	InitialiserGraphique();
	/* Taille de la fenêtre */
    CreerFenetre(10,10,500,500);
    RemplirTriangle(250,0,0,500,500,500);
    while (1) {
    	puts("");
    }
    FermerGraphique();
	return EXIT_SUCCESS;
}