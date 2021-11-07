#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int* p = NULL;
	int* x = NULL;
	int entier;


	printf("Combien d'entier voulez-vous saisir ?\n");
	scanf("%d",&entier);
	printf("\n");
	p=malloc(entier*sizeof(int));
	x=malloc(entier*sizeof(int));

	if (p==NULL){
		printf("Erreur : p est nul.");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < entier; i++)
	{
		printf("Entrez la valeur ");
		scanf("%d", &p[i]); 
	}


	for (int i = 0; i < entier; i++)
	{
		for (int j = 1; j < entier; j++)
		{
			if (p[i]=!p[j])
			{
				p[i]=x[i];
			}
		}
	}

	for (int i = 0; i < entier; ++i)
	{
		printf("%d ", x[i]);
	}
	printf("\n");

	free(p);


}