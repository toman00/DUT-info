#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
	pid_t pid;
	
	if (argc < 2) {
		perror("argument pas bon");
		exit (0);
	}

	pid = fork();

	if (pid == 0) {
		if (execvp(argv[1], &argv[1]) == -1)
			/* argv+sizeof(char*) c'est trop grand */
			{ 
				perror("dans le exec");
				exit (0);
			}
		
	} else {
		wait(NULL);
	}
	return EXIT_SUCCESS;
}