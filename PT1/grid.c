/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient les fonctions sur la grille.
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
#include <graph.h>
/*------------------------------*/
/* Inclusions librairies projet */
/*------------------------------*/
#include "grid.h"
#include "defines.h"

/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction Initialisation des attributs de la grille.
 *  pGrid : Grille en cours.
 * Retour : Aucun.
 */
void InitGrid(typeGrid *pGrid) {
    int x = 0, y = 0;
    int xOffset, yOffset; /* Offsets de position de case */

    /* Calcul de la taille de case */
    int caseSize = GRID_PIXELS_SIZE / pGrid->nbCases;

    /* Allocation mémoire pour les Colonnes (X) */
    pGrid->cases = (typeCase **) malloc(sizeof(typeCase *) * pGrid->nbCases);

    /* Allocation mémoire pour les Lignes (Y) */
    for (y=0; y < pGrid->nbCases; y++) {
        pGrid->cases[y] = (typeCase *) malloc(sizeof(typeCase) * pGrid->nbCases);
    }

    /* Pour les X */
    for (x = 0; x < pGrid->nbCases; ++x) {
        /* Position X de la case */
        xOffset = x * caseSize;
        /* Pour les Y */
        for (y = 0; y < pGrid->nbCases; ++y) {
            /* Position Y de la case */
            yOffset = y * caseSize;

            /* Initialisation des paramètres de chaque case de la grille */
            pGrid->cases[x][y].x = xOffset;
            pGrid->cases[x][y].y = yOffset;
            pGrid->cases[x][y].width = caseSize;
            pGrid->cases[x][y].height = caseSize;
            pGrid->cases[x][y].rectColor = COLOR_BLACK;
            pGrid->cases[x][y].backColor = COLOR_BACK;
            pGrid->cases[x][y].hoverColor = COLOR_CASE_OVER;
            pGrid->cases[x][y].whoIn = CASE_MODE_FREE;
            pGrid->cases[x][y].playerColor = COLOR_BACK;
        } /* for (y = 0; y < pGrid->nbCases; ++y) */
    } /* for (x = 0; x < pGrid->nbCases; ++x) */
}

/* Fonction qui dessine la grille.
 *  pGrid : Grille en cours.
 * Retour : Aucun.
 */
void DrawGrid(typeGrid *pGrid) {
    int x = 0, y = 0;

    /* Pour les X */
    for (x = 0; x < pGrid->nbCases; ++x) {
        /* Pour les Y */
        for (y = 0; y < pGrid->nbCases; ++y) {
            /* Dessine la case */
            DrawCase(&pGrid->cases[x][y]);
        }
    }
}

/* Fonction de recherche de case cliquée.
 *  pGrid : La grille.
 *  mouseX, mouseY : Coordonnées de la souris.
 *  pCaseX, pCaseY : Coordonnées de la case à mettre à jour.
 * Retour :
 *  1 si c'est à mis jour, 0 sinon.
 */
int GetCaseFromMouse(typeGrid *pGrid, int mouseX, int mouseY, int *pCaseX, int *pCaseY) {
    int x = 0, y = 0;
    int foundCase = 0; /* 1 si case trouvée, 0 sinon */

    /* Pour les X */
    for (x = 0; (x < pGrid->nbCases) && (foundCase == 0); ++x) {
        /* Pour les Y */
        for (y = 0; (y < pGrid->nbCases) && (foundCase == 0); ++y) {
            /* Dans la case ? */
            if (TestInCase(&pGrid->cases[x][y], mouseX, mouseY)) {
                /* Clique dans la case [x][y] ! */
                *pCaseX = x;
                *pCaseY = y;
                foundCase = 1;
            }
        }
    }

    /* Retourne si l'on a trouvé */
    return foundCase;
}

/* Fonction de libération mémoire de la grille.
 *  pGrid : La grille.
 * Retour : Aucun.
 */
void FreeGrid(typeGrid *pGrid) {
    int x = 0;

    /* Libération mémoire des Lignes (Y) */
    for (x = 0; x < pGrid->nbCases; x++)
        free(pGrid->cases[x]);

    /* Libération mémoire des Colonnes (X) */
    free(pGrid->cases);
}
