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
	puts("");
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

/* Fonction qui trie la liste :
 * - Retire le + grand élément de la liste d'entrée
 * - Ajoute cet élément à la seconde liste 
 *  On recommence tant qu'il y a des élements dans la 1ere liste */
Node* sortList(struct Node* n) {
	/* Buffer qui garde le + grand nombre */
    unsigned short greater = n->Data;
    Node* temp = n;
    Node* scout = n;
	Node* delete = n; /* Redirect sur le next de ce maillon */
	Node* newValue = n; /* Valeur qui sera à supprimer */
	/* Nouvel liste triée */
	Node* newNode = NULL;
	/* Si la liste est nulle */
	if (n == NULL) {
		puts("Empty.");
	}
	else { /* Sinon */
		/* Tant qu'il reste un élément dans la liste d'entrée */
		while (n != NULL) {
			greater = n->Data;
			temp = n;
			scout = n;
			delete = n;
			newValue = n;
			while (scout->Next != NULL) {
				scout = scout->Next;
				/* Si on trouve */
				if (scout->Data > greater) {
					greater = scout->Data;
					delete = temp;
					newValue = temp->Next;
				}
				/* Maillon précédant l'élément le + grand */
				temp = temp->Next;			
			}
			/* Si la plus valeur est à la première adresse */
			if (newValue == n) {
				n = newValue->Next;
				newValue->Next = NULL;
				newNode = appendList(newNode, newValue->Data);
			}
			else { /* Sinon */
				delete->Next = newValue->Next;
				/* On ajoute le plus grand élément à la liste triée */
				newValue->Next = NULL;
				/*printf("%d, %d\n",delete->Data, newValue->Data);*/
				newNode = appendList(newNode, newValue->Data);
			}
		}
	}
	return newNode;
}

/* Bloc principal */
int main(int argc, char *argv[]) {
	unsigned short value = 0;

	int numbers = 10; /* Nombre de valeurs aléatoires */
	/* Initialisation du pseudo générateur  */
	srand(time(NULL));

	/* Initialisation de la liste */
	Node* head = NULL;
	Node* sorted = NULL;

	/* Ajoute 10 valeurs aléatoires à la liste chainee
     * non triée */
	while (numbers > 0) {
		value = (unsigned short) rand() % (999 + 1 - 111) + 111;
		head = appendList(head,value);
		--numbers;
	}

	/* On affiche liste non-triee */
    puts("Liste non-triee :");
	printList(head);

	/* On trie la liste */
	sorted = sortList(head);

	/* On affiche la liste triee */
	puts("Liste triee :");
	printList(sorted);


	/* On libère toute les listes chainees */
	freeList(head);
	freeList(sorted);

	return EXIT_SUCCESS;
}