#include <stdio.h>
#include <stdlib.h>

int main(void){

int moyenne;

printf("Entrez votre moyenne au BAC : ");
scanf("%d",&moyenne);
if (moyenne<0&&moyenne>20){
	printf("ERROR, la moyenne doit être comprise entre 0 et 20");
}else if (moyenne>=10&&moyenne<12){
	printf("Vous n'avez pas de mention.\n");
}else if (moyenne>=12&&moyenne<14){
	printf("Vous avez mention Assez Bien, félicitations !\n");
}else if (moyenne>=14&&moyenne<16){
	printf("Vous avez mention Bien, félicitations !\n");
}else if (moyenne>=16){
	printf("Vous avez mention Très bien, WOAW !\n");
}else{
	printf("Vous n'avez pas le BAC, à l'année prochaine !\n");
}
}
