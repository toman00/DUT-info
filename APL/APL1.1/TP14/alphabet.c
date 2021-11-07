#include <stdio.h>
#include <stdlib.h>


int main(void) {
  char min, maj;
  char *p = NULL;
 
  for(min = 'a', maj = 'A'; maj <= 'Z'; min++, maj++) {
    /* Forme conditionnelle :  p=&min ? si oui, alors ... sinon : ...*/
    p = (p == &min) ? &maj : &min;
    putchar(*p);
  }
  putchar('\n');
  return EXIT_SUCCESS;
}