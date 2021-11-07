#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	double reel = 0;
	char car = 0;
	int i = 0;

	printf("Saisissez un nombre réel : ");
	scanf("%lf",&reel);
	printf("%e\n", reel);
	printf("Saisissez un caractère : ");
	scanf(" %c",&car);
	printf("\n");


	for (i;i<5;++i)printf("%c\n",car);
}