/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient les fonctions sur les players
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

/*----------------------*/
/* Inclusions standards */
/*----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*------------------------------*/
/* Inclusions librairies projet */
/*------------------------------*/
#include "player.h"

/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction de vérification si la case est disponible
 *  pPlayer : Le joueur courant.
 *  caseX : Position en X de la case.
 *  caseY : Position en Y de la case.
 *  gridSize : La taille de la grille.
 * Retour : 1 si possible, 0 sinon.
 */
int CaseIsPossible(typePlayer *pPlayer, int caseX, int caseY, int gridSize) {
    int possible = 0; /* 1 si possible, 0 sinon */

    /* Déclaration des ranges possibles pour les cases */
    int minX = pPlayer->gridX - 1; /* Minimum sur X */
    int maxX = pPlayer->gridX + 1; /* Maximum sur X */
    int minY = pPlayer->gridY - 1; /* Minimum sur Y */
    int maxY = pPlayer->gridY + 1; /* Maximum sur Y */

    /* Borne les ranges : entre [0 .. taille de la grille - 1] */
    if (minX < 0) {
        minX = 0;
    }
    if (maxX >= gridSize) {
        maxX = gridSize - 1;
    }
    if (minY < 0) {
        minY = 0;
    }
    if (maxY >= gridSize) {
        maxY = gridSize - 1;
    }

    /* Test sur la position de la case dans les ranges possibles */
    if ((caseX >= minX) && (caseX <= maxX)) {
        /* C'est bon sur les X */
        if ((caseY >= minY) && (caseY <= maxY)) {
            /* C'est bon sur les Y */
            possible = 1;
        }
    }

    /* Retourne si c'est possible */
    return possible;
}

/* Fonction qui calcule le nombre de cases disponibles pour un joueur.
 * pPlayer : Le joueur courant.
 * pGrid : La grille.
 * Retour :
 *  Nombre de cases disponibles.
 */
int GetFreeCases(typePlayer *pPlayer, typeGrid *pGrid) {
    /* Nombre de cases possibles */
    int nbFreeCases = 0;
    int x = 0;
    int y = 0;

    /* Déclaration des ranges possibles pour les cases */
    /* Position (X, Y) du joueur +/- 1 */
    int minX = pPlayer->gridX - 1;
    int maxX = pPlayer->gridX + 1;
    int minY = pPlayer->gridY - 1;
    int maxY = pPlayer->gridY + 1;

    /* Borne les ranges : entre [0 .. taille de la grille - 1] */
    if (minX < 0) {
        minX = 0;
    }
    if (maxX >= pGrid->nbCases) {
        maxX = pGrid->nbCases - 1;
    }
    if (minY < 0) {
        minY = 0;
    }
    if (maxY >= pGrid->nbCases) {
        maxY = pGrid->nbCases - 1;
    }

    /* Parcourir toutes les cases autour de la position actuelle du joueur */
    /* Pour tous les X */
    for (x = minX; x <= maxX; ++x) {
        /* Pour tous les Y */
        for (y = minY; y <= maxY; ++y) {
            /* Si case est libre */
            if (pGrid->cases[x][y].whoIn == CASE_MODE_FREE) {
                /* Si le joueur n'est pas dans la case */
                if (!((pPlayer->gridX == x) && (pPlayer->gridY == y))) {
                    /* Incrémente le nombre de cases libres */
                    nbFreeCases++;
                }
            }
        }
    }

    /* Retourne le résultat */
    return nbFreeCases;
}

/* Fonction de recherche de cases aléatoires par l'IA.
 *  pPlayer : Le joueur courant.
 *  pGrid : La grille.
 *  pPlayerX : La case X trouvée.
 *  pPlayerY : La case Y trouvée.
 * Retour : Aucun.
 */
void GetIAFreeCases(typePlayer *pPlayer, typeGrid *pGrid, int *pPlayerX, int *pPlayerY) {
    /* Dans le cas de la demande de placement, on prend la position du joueur IA */
    /* Déclaration des ranges possibles pour les cases */
    /* Position (X, Y) du joueur +/- 1 */
    int minX = pPlayer->gridX - 1;
    int maxX = pPlayer->gridX + 1;
    int minY = pPlayer->gridY - 1;
    int maxY = pPlayer->gridY + 1;

    /* Borne les ranges : entre [0 .. taille de la grille - 1] */
    if (minX < 0) {
        minX = 0;
    }
    if (maxX >= pGrid->nbCases) {
        maxX = pGrid->nbCases - 1;
    }
    if (minY < 0) {
        minY = 0;
    }
    if (maxY >= pGrid->nbCases) {
        maxY = pGrid->nbCases - 1;
    }

    /* Initialisation du random */
    /* Utilisation de la fonction "clock()" pour nombre aléatoire plus rapide */
    srand(clock());

    /* Réglage aléatoire de la position X et Y du joueur IA */
    /* Si IA non placée, c-à-d 1er tour */
    if ((pPlayer->gridX == DEFAULT_POS_NONE) &&
        ((pPlayer->gridY == DEFAULT_POS_NONE))) {
        /* Recherche au hasard d'une case vide dans la grille */
        *pPlayerX = rand()%(pGrid->nbCases);
        *pPlayerY = rand()%(pGrid->nbCases);
    }
    else {
        /* Recherche au hasard d'une case vide dans les ranges */
        /* Si plus de place en X : case X actuelle */
        if ((maxX - minX) == 0) {
            *pPlayerX = pPlayer->gridX;
        } else {
            /* +1 pour atteindre la derniere valeur */
            *pPlayerX = minX + rand()%(maxX - minX + 1);
        }

        /* Si plus de place en Y : case Y actuelle */
        if ((maxY - minY) == 0) {
            *pPlayerY = pPlayer->gridY;
        } else {
            /* +1 pour atteindre la derniere valeur */
            *pPlayerY = minY + rand()%(maxY - minY + 1);
        }
    }
}

/* Fonction de placement d'un joueur.
 *  pPlayer : Le joueur en cours.
 *  playGrid : La grille de jeu.
 *  posX : Position X de la case.
 *  posY : Position Y de la case.
 * Retour :
 *  1 si placé, 0 sinon.
 */
int PlacePlayer(typePlayer *pPlayer, typeGrid *pGrid, int posX, int posY) {
    int foundX = posX; /* Case trouvée en X */
    int foundY = posY; /* Case trouvée en Y */
    int retPlaced = 0; /* 1 si placé, 0 sinon */

    /* Si case trouvée */
    if ((foundX != -1) && (foundY != -1)) {
        /* Case libre ? */
        if (pGrid->cases[foundX][foundY].whoIn == CASE_MODE_FREE) {
            /* Case est libre */

            /*----------------*/
            /* Si déplacement */
            /* Si placé = 0 -> demande de placement */
            if (pPlayer->placed == 0) {
                /* Mise à jour de la position actuelle du joueur          */
                /* Si position actuelle du joueur = NONE -> 1er placement */
                if (pPlayer->roundCount == 0) {
                    /* Prise en compte de la case trouvée */
                    pPlayer->gridX = foundX;
                    pPlayer->gridY = foundY;

                    /* Case occupée par pion */
                    pGrid->cases[foundX][foundY].whoIn = CASE_MODE_PAWN;
                    pGrid->cases[foundX][foundY].playerColor = pPlayer->color;
                    pPlayer->placed = 1;

                    /* Placement fait */
                    retPlaced = 1;
                } else {
                    /* Tester si la case est adjacente */
                    if (CaseIsPossible(pPlayer, foundX, foundY, pGrid->nbCases)) {
                        /* Ancienne position libre */
                        pGrid->cases[pPlayer->gridX][pPlayer->gridY].whoIn = CASE_MODE_FREE;

                        /* Prise en compte de la case trouvée */
                        pPlayer->gridX = foundX;
                        pPlayer->gridY = foundY;

                        /* Case occupée par pion */
                        pGrid->cases[foundX][foundY].whoIn = CASE_MODE_PAWN;
                        pGrid->cases[foundX][foundY].playerColor = pPlayer->color;
                        pPlayer->placed = 1;

                        /* Placement fait */
                        retPlaced = 1;
                    }
                }
            }
            /*--------------------*/
            /* Si blocage de case */
            /* Si placé = 1 et blocked = 0 -> Demande de blocage */
            else if (pPlayer->blocked == 0) {
                /* Case occupée par croix */
                pGrid->cases[foundX][foundY].whoIn = CASE_MODE_BLOCKED;
                pGrid->cases[foundX][foundY].playerColor = pPlayer->color;
                pPlayer->blocked = 1;

                /* Placement fait */
                retPlaced = 1;
            }
        }
    }

    /* Retourne si placé */
    return retPlaced;
}




