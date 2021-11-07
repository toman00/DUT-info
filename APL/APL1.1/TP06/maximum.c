#include <stdio.h>
#include <stdlib.h>

int main(void){

int entier1;
int entier2;
int entier3;
int res;

printf("Lesquelles sont les plus grands des 3 ?\n");
printf("Entrez le premier nombre :");
scanf("%d",&entier1);
printf("Entrez le second nombre :");
scanf("%d",&entier2);
printf("Entrez le troisième nombre :");
scanf("%d",&entier3);

if (entier1>entier2){
	res=entier1;
}else{
	res=entier2;
}
if (entier3>res){
	res=entier3;
} 
printf("%d est le plus grand de tous.\n",res);
}
