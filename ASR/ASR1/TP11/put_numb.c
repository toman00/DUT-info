/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	/* Variables */
	unsigned long f, x, i, l, n, offset;
	/* Messages d'erreur */
	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s <file_name> <32-bit int in Hex> <Offset in Hex>\n", argv[0]);
		exit(1);
	}
	/* Ouverture du fichier en write only */
	f = open(argv[1],O_WRONLY);
	if (f == -1) {
		exit(2);
	}

	x = (unsigned) strtol(argv[2],NULL,16);
	i = (unsigned) strtol(argv[3],NULL,16);

	offset = 4 * i;
	l = lseek(f,0,SEEK_END);
	if (offset > l) {
		offset = l;
	}

	l = lseek(f,offset,SEEK_END);
	n = write(f,&x,4);
	if (n == -1) {
		printf("Writing file failed");
		exit(3);
	}
	return EXIT_SUCCESS;
}