#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	double premier = sqrt(fabs(log(0.5)));
	double deuxieme = sin(M_PI/6);
	double trois = atan(pow(2,13));
	double quatre = pow(exp(-1),4);
	double cinq = log(-3);
	double six = pow(2,sqrt(2));



	printf("%lf\n",premier);
	printf("%lf\n", deuxieme);
	printf("%lf\n", trois);
	printf("%lf\n",quatre);
	printf("%lf\n",cinq);
	printf("%lf\n",six);

}