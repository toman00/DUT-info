/* Inclusions */
#include <stdio.h>
#include <stdlib.h>

void exemple(unsigned n) {
  if (n != 0) {
    putchar('>');
    exemple(n-1);
    putchar('<');
  } else
    putchar('O');
}

int main(int argc, char *argv[]) {
	/*  */
	exemple(3);
	puts("");

	return EXIT_SUCCESS;
}