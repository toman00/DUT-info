#include <stdio.h>
#include <stdlib.h>

extern char **environ;
/* 
 * print tous les pointeurs de l'environnement
 */

int main(int argc, char *argv[]) {
	int ind; 
	char **ptr;
	
	for (ind = 0; ind < argc; ind++)  printf("%s\n", argv[ind]); 
	
	ptr = environ;

	while (*ptr != NULL) printf("%s\n", *ptr++);
		
	return EXIT_SUCCESS;
}
