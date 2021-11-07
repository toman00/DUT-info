#include <stdio.h>
#include <stdlib.h>

int main(void){

int produit;
int produit2;

printf("***\t + OR - \t***\n");
printf("Rentrez le premier nombre : ");
scanf("%d",&produit);
printf("Rentrez le second nombre : ");
scanf("%d",&produit2);

if (produit>0&&produit2>0){
	printf("Le produit est positif\n");
}
else{
	printf("Le produit est négatif\n");

}
}
