#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned long int a=6UL;
	unsigned int b=0x6;
	double c=6.0;
	unsigned char d='\66';

	printf("%lu\n",a);
	printf("%o\n",b);
	printf("%0.0lf\n",c);
	printf("%c\n",d);

return EXIT_SUCCESS;

}