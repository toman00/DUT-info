/* Inclusions */
#include <stdio.h>
#include <stdlib.h>


int f(int n) { 
  if (n>100)
    return n-10;
  else
    return f(f(n+11));
}


int main(int argc, char *argv[]) {


	return EXIT_SUCCESS;
}