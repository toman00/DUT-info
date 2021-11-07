#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
char buffer [256];
int file,x,n;
x=1;a
if (argc>2){
	perror("Only one argument needed !");
	exit(1);
}

if (argc<2){
	perror("One argument needed !");
	exit(2);
}

file=open(argv[1],O_RDONLY);

if (file==-1){
	perror("File cannot be opened");
	exit(3);
}
else {
	while (x!=0){
		x=read(file,buffer,256);
		n=write(1,buffer,x);
	}
	close(file);

exit (0);
}
}