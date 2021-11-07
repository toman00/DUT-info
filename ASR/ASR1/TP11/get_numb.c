/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[]) {
	int n,z,l;
	unsigned int offset,i;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s <file_name> <offset>\n", argv[0]);
		exit(1);
	}

	f=open(argv[1],O_RDONLY);
	if (f == -1)
	{
		perror("Opening file fails!\n");
		exit(2);
	}
	i = (unsigned int) strtol(argv[1],NULL,16);
	offset = i * sizeof(int);
	l = lseek(f,offset,SEEK_SET);
	if (l == -1)
	{
		perror("fseek fails!\n");
		exit(3);
	}

	n = read(f,buf,sizeof(int));
	if (n < sizeof(int))
	{
		printf("Nothing to read.\n");
		exit(4);
	}
	else {
		printf("The number at offset %ld is 0%08x --> %d\n",i,z,n);
	}
	close(f);

	exit(0);
	return EXIT_SUCCESS;
}