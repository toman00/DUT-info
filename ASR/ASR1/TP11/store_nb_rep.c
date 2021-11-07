/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	/* Variables */
	char buffer[256];
	int f,i=1,x,n,m;

	/* Si il n'y a pas assez d'argument */
	if ( argc < 2 )
	{
		fprintf(stderr, "Usage : %s <file_name>\n", argv[0]);
		exit(1);
	}

	f=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0600);
	
	/* Si le fichier rencontre un problème */
	if (f == -1)
	{
		perror("Opening file failed.");
		exit(2);
	}

	/* Tant que la fin du fichier n'est pas atteint */
	while (i != 0){
		write(1,"Numb -->",9);
		n = read(0,buffer,256);
		if (n != 0)
		{
			n = (int) strtol(buffer,NULL,0);
		}
		
		m = write(n,&x,sizeof(int));
		if (m == -1)
		{
			perror("Writing in file failed !");
			exit(3);
		}
	}
	close(f);
	exit(0);

	return EXIT_SUCCESS;
}