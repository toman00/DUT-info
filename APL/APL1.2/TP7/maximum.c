/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Création de la liste chaînée */
typedef struct Node Node;
struct Node {
	unsigned short Data; /* Data to put into the list */
	struct Node* Next; /* Address of the next node */
};

/* Fonction pour afficher tout les noeuds */
void printList(Node* n) { 
    while (n != NULL) { 
        printf(" %d ", n->Data); 
        n = n->Next;
    } 
}

/* Fonction pour libérer la mémoire */
void freeList(struct Node* head) { 
	Node* tmp;
	while (head	 != NULL) { 
		tmp = head;
		head = head->Next; 
		free(tmp);
    } 
}

/* Fonction pour remplir aléatoirement la liste (ajoute la valeur
 * au début). */
Node* appendList(Node* head, unsigned short newValue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	/* Si le malloc échoue */
	if (newNode == NULL) {
		fprintf(stderr,"Cannot allocate memory for this node.\n");
		exit(2);
	}
	newNode->Data = newValue;
	newNode->Next = head;
	return newNode;
}

/* Fonction qui recherche le plus grand nombre de la liste */
void searchList(struct Node* n) { 
    unsigned short greater = n->Data;
	if (n == NULL) {
		puts("Empty.");
	}
	else {
		while (n != NULL) {  
			if (n->Data > greater) {
				greater = n->Data;
			}
			/* Si on atteint la fin de la liste
			* on affiche le plus grand nombre
			* trouvé */
			if (n->Next == NULL) {
				printf("\t|\t%d\t|\n", greater);
			}
			n = n->Next;
		}
	} 
}

/* Bloc principal */
int main(int argc, char *argv[]) {
	unsigned short value = 0;

	int numbers = 10; /* Nombre de valeurs aléatoires */
	/* Initialisation du pseudo générateur  */
	srand(time(NULL));

	/* Initialisation de la liste */
	Node* head = NULL;


	/* Ajoute 10 valeurs aléatoires à la liste chainee */
	while (numbers > 0) {
		value = (unsigned short) rand() % (999 + 1 - 111) + 111;
		head = appendList(head,value);
		--numbers;
	}

	/* On affiche toute la liste chainee */
	printList(head);
	/* On recherche le plus grand */
	searchList(head);
	/* On libère toute la liste chainee */
	freeList(head);

	return EXIT_SUCCESS;
}