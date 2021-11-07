#include <stdio.h>
#include <stdlib.h>

int main(void){
	/* Variables */
	int triple;
	printf("***\t QUELLE TRIPLE EST LE PLUS PROCHE ? \t***\n");
	printf("Entrez un nombre : ");
	scanf("%u",&triple);
	 if ((triple%3)==0){
		printf("%d est déjà un multiple de 3\n", triple);
		exit(0);
	 }
	 else if((triple%3)==1){
		 triple=triple-1;	
	 }
	 else{
		 triple=triple+1;
	 }



	printf("Le triple le plus proche est %d\n",triple);

	return EXIT_SUCCESS;
}
