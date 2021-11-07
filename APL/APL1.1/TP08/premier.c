#include <stdio.h>
#include <stdlib.h>

int main(void){

	int nb;
	int premier=0;
	int i;

	printf("Rentrez un nombre : ");
	scanf("%d",&nb);

	for (i=2;i<10;i=i+1){
		if (nb%i==0){
			premier=premier+1;
		}
	}
	if (premier>=2){
		printf("\nCe n'est pas un nombre premier.\n");
	}
	else{
		printf("\nC'est un nombre premier.\n");
	}


}