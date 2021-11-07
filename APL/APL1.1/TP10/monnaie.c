#include <stdio.h>
#include <stdlib.h>

int main(void){

double piece2=0;
double vingtcents=0;
double cent=0;
double arendre=0;
double rendu=0;

printf("Rendu : ");
scanf("%lf",&rendu);

while (rendu>=2){
	rendu=rendu-2;
	++piece2;
}
arendre=piece2*2+vingtcents*0.2+cent*0.01;
printf("%lf",arendre);



}