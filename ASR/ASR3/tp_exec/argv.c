#include <stdio.h>
#include <unistd.h>
#define NMAX 5
main() {
	char *argv[NMAX]; /* NMAX > 3 */
	
	argv[0] = "ls"; argv[1] = "-l"; argv[2]="/"; argv[3]=NULL; 
	
	execv("/bin/ls", argv); 
	perror("execv");
}
