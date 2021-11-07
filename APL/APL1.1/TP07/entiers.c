#include <stdio.h>
#include <stdlib.h>

int main(void){

	int entier1;
	int entier2;



	printf("Tapez un entier : ");
	scanf("%d",&entier1);
	printf("\nTapez un second entier : ");
	scanf("%d",&entier2);
	
		
	if (entier1<entier2){
		while (entier1<entier2){
			printf("%d, ",entier1);
			entier1=entier1+1;
		}	
		printf("%d\n",entier2);
	}
	else{
		while (entier2<entier1){
			printf("%d, ",entier2);
			entier2=entier2+1;
		}	
		printf("%d\n",entier1);

	}
}