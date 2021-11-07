#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Création de la liste chaînée */
typedef struct Node chaine;
struct Node {
	char letter; /* contient une seule lettre */
	struct Node* Next; /* Adress of the next node */
};



/* Fonction pour remplir aléatoirement la liste (ajoute la valeur
 * au début). */
chaine* appendList(chaine* head, unsigned short newValue) {
	chaine* newNode = (chaine*)malloc(sizeof(chaine));
	/* Si le malloc échoue */
	if (newNode == NULL) {
		fprintf(stderr,"Cannot allocate memory for this node.\n");
		exit(2);
	}
	newNode->letter = newValue;
	newNode->Next = head;
	return newNode;
}

/* Fonction pour afficher tout les noeuds */
void printList(chaine* n) { 
    while (n != NULL) { 
        printf(" %c ", n->letter); 
        n = n->Next; 
    } 
}

/* Fonction qui transforme une chaine de caractère 
 * en une liste chainée */
chaine* strToLinkedList(char* string) {
    chaine* str = NULL;

    /* S'il y a quelque chose dans la chaine tableau */
    if (string) {
        chaine* str = (chaine*)malloc(sizeof(chaine));
        int length = (int) strlen(string);
        int ptr; /* Pointeur de la chaine */
        int i;
        /* Si le malloc échoue */
        if (str == NULL) {
            fprintf(stderr,"Cannot allocate memory for this node.\n");
            exit(2);
	    }
        /* Parcourt toute la chaine de caractère */
        for (i = 0; i < length; ++i) {
            str = appendList(str,string[i]);
        }
    }
    printList(str);

    return str; 
}


/* Fonction qui transforme une liste chainee 
 * en chaine de caractère */

/* Fonction pour libérer la mémoire */
void freeList(chaine* head) { 
	chaine* scout;
	while (head	 != NULL) { 
		scout = head;
		head = head->Next; 
		free(scout);
    } 
}

int main(int argc, char** argv) {
    chaine* head = NULL;
    char test[] = "test";

    /* On récupère la liste chainée */
    head = strToLinkedList(test);
    /* On affiche la liste chainee */
    printList(head);
    printf("%d", head);
    /* Libération mémoire */
    freeList(head);

    return EXIT_SUCCESS;
}