#include <stdio.h>
#include <stdlib.h>

int main(void){

char a=77;
unsigned char b=77;
short int c=77;
unsigned short int d=77;
int e=77;
unsigned int f=77U;
long int g=77L;
unsigned long int h=77UL;
long long int i=77LL;
unsigned long long int j=77ULL;
float k=77.f;
double l=77;
long double m=77L;



printf("%hhi\n",a);
printf("%hhi\n",b);
printf("%hi\n",c);
printf("%hu\n",d);
printf("%d\n",e);
printf("%u\n",f);
printf("%li\n",g);
printf("%lu\n",h);
printf("%lli\n",i);
printf("%llu\n",j);
printf("%lf\n",l);
printf("%Lf\n",m);

return EXIT_SUCCESS; 
}
