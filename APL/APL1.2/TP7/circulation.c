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
void printList(struct Node* n) { 
    while (n != NULL) { 
        printf(" %d ", n->Data); 
        n = n->Next; 
    } 
}

/* Fonction pour libérer la mémoire */
void freeList(struct Node* head) { 
	Node* scout;
	while (head	 != NULL) { 
		scout = head;
		head = head->Next; 
		free(scout);
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

/* Fonction qui demande le nombre de rotation a effectuer 
 * et effectue le nombre de rotation nécéssaire */
Node* rotationListPos (Node* head) {
	Node* scout = head;
	Node* temp = head;
	while (scout->Next != NULL) {
		/* Scout permet de vérifier si le prochain maillon 
		 * contient une valeur Next nulle, et donc fin de 
		 * la chaine. 
		Scout est toujours avancée d'un maillon par rapport à
		 * temp ! */
		scout = scout->Next;
		/* Si c'est le cas, temp attribut à l'avant dernière
		* valeur Next une adresse nulle. */
		if (scout->Next == NULL) {
			/* On peut donc mettre la dernière valeur (ici 
			* scout donc, avec Next à la suite de l'ancien
			* premier maillon */
			
			scout->Next = head;
			head = temp->Next;
			temp->Next = NULL;

			return head;
			break;
		}
		temp = temp->Next;
	}
}

/* Si la rotation est négative on déplace
 * la premiere valeur a la derniere position */
Node* rotationListNeg (Node* head) {
	/* Cherche la dernière valeur */
	Node* scout = head;
	/* Récupère l'adresse de la dernière valeur */
	Node* second = head->Next;
	/* Prend le pointeur vers la 2eme valeur 
	 * de la liste, si elle existe */
	
	/* Boucle pour récupérer l'adresse de la dernière valeur */
	while (scout->Next != NULL) {
		/* Scout permet de vérifier si le prochain maillon 
		 * contient une valeur Next nulle, et donc fin de 
		 * la chaine. */
		scout = scout->Next;
	}
	head->Next = NULL;
	scout->Next = head;
	return second;
}

/* Bloc principal */
int main(int argc, char *argv[]) {
	unsigned short value = 0;
	int rotations = 0; /* Nombre de rotation a effectue */
	int numbers = 10; /* Nombre de valeurs aléatoires */
	/* Initialisation du pseudo générateur  */
	srand(time(NULL));

	/* Initialisation de la liste */
	struct Node* head = NULL; 
	
	/* Ajoute 10 valeurs aléatoires à la liste chainee */
	while (numbers > 0) {
		value = (unsigned short) rand() % (999 + 1 - 111) + 111;
		head = appendList(head,value);
		--numbers;
	}
	
	/* On affiche toute la liste chainee */
	printList(head);
	/* On demande à l'utilisateur de choisir le nb 
	 * de rotation */
	puts("");
	printf("Choisissez une rotation: ");
	scanf("%d", &rotations);
	puts("");
	
	/* S'il y a une rotation != de 0 */
	if (rotations != 0) {
		/* Si le nb de rotation est positif */
		while (rotations > 0) {
			head = rotationListPos(head);
			--rotations;
		}
		/* Si la rotation est négative */
		while (rotations < 0) {
			head = rotationListNeg(head);
			++rotations;
		}
	}
	else {
		puts("Aucune rotation a effectuer.");
		return EXIT_SUCCESS;
	}
		
	/* On re-affiche le resultat de/des rotation(s) effectuee(s) */
	printList(head);
	/* On libère toute la liste chainee */
	freeList(head);

	return EXIT_SUCCESS;
}