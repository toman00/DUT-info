#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	double x1 = 0;
	double x2 = 0;
	double y1 = 0;
	double y2 = 0;
	double distance = 0;


	printf("Entrez l'axe x1 : ");
	scanf("%Lf",&x1);
	printf("\nEntrez l'axe y1 : ");
	scanf("%Lf",&y1);

	printf("\nEntre l'axe x2 :");
	scanf("%Lf",&x2);
	printf("\nEntrez l'axe y2 : ");
	scanf("%Lf",&y2);
	

	distance = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	distance = fabs(distance);

	printf("La distance entre ces deux points est de %Lf\n", distance);




}