#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	/* Nombres de fois que le programme a été executé
	 * 1 fois au minimum */
	int times = 0;
	
	/* Ouverture du flux en lecture/écriture */
	FILE* flux = fopen("registre.txt", "r+");
	/* On lit le nombre de fois que le fichier a été écrit */
	fread(&times,sizeof(int),1,flux);
	fseek(flux,0,SEEK_SET);
	/* On écrit le nb de fois qu'il a été exécuté 
	 * dans le fichier*/
	times += 1;
	fwrite(&times,sizeof(int),1,flux);
	printf("%d",times);


	fclose(flux);
	return EXIT_SUCCESS;
}