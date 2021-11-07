#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	execlp("ls", "ls", "-l", "/", NULL);
	return 0;
}
