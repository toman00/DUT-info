#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
char buffer [256];
int file,file2,x,n;
x=1;
if (argc>3){
	perror("Only one argument needed !");
	exit(1);
}

if (argc<3){
	perror("One argument needed !");
	exit(2);
}

file=open(argv[1],O_RDONLY);


if (file==-1){
	perror("First file cannot be opened");
	exit(3);
}

if (file2=open(argv[2],O_WRONLY)!=0){
	file2=open(argv[2],O_CREAT);
	if (file2==-1){
		perror("Creation file failed, please retry.");
		exit(4);
	}
	file2=open(argv[2],O_WRONLY);
}

else {
	while (x!=0){
		x=read(file,buffer,256);
		n=write(file2,buffer,x);
	}
	close(file);
	close(file2);

exit (0);
}
}