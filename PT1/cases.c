/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient les fonctions sur les cases.
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
/*------------------------------*/
/* Inclusions librairies projet */
/*------------------------------*/
#include "cases.h"


/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction d'effacement de case.
 *  pCase : Pointeur vers la case à effacer.
 * Retour : Aucun.
 */
void ClearCase(typeCase *pCase) {
    /* Dessin du rectangle de la case */
    ChoisirCouleurDessin(pCase->rectColor);
    DessinerRectangle(
        pCase->x, pCase->y,
        pCase->width, pCase->height);

    /* Effacer le contenu actuel */
    ChoisirCouleurDessin(pCase->backColor);
    RemplirRectangle(
        pCase->x + 1, pCase->y + 1,
        pCase->width - 1, pCase->height - 1);
}

/* Fonction qui permet de tester si la position de souris est sur la case.
 *  pCase : Pointeur vers la case concernée.
 *  posX, posY : Coordonnées de la souris à tester.
 * Retour :
 *  1 si dans la case et 0 sinon.
 */
int TestInCase(typeCase *pCase, int posX, int posY) {
    int inCase = 0; /* 1 si c'est sur la case, 0 sinon */

    /* Test si la position de la souris est dans le rectangle de la case */
    /* Teste les X */
    if ((posX > pCase->x) && (posX < (pCase->x + pCase->width))) {
        /* Coordonnée X dans la zone de la case */
        /* Teste les Y */
        if ((posY > pCase->y) && (posY < (pCase->y + pCase->height))) {
            /* Coordonnée Y dans la zone de la case */
            inCase = 1;
        }
    }

    /* Retourne le résultat du test */
    return inCase;
}

/* Fonction de dessin de la case.
 *   pCase : Pointeur vers la case concernée.
 * Retour : Aucun.
 */
void DrawCase(typeCase *pCase) {
    int mouseHover = 0; /* 1 si souris sur une case */
    /* Taille des barres horizontale/verticale de la croix */
    double barSize = (double) pCase->height / 7.0;

    /* Récupération de la souris */
    SourisPosition();

    /* Est-ce que la souris est au-dessus de la case ? */
    mouseHover = TestInCase(pCase, _X, _Y);

    /* Efface la case */
    ClearCase(pCase);

    /* Si personne dedans et survol souris ? */
    if ((pCase->whoIn == CASE_MODE_FREE) && (mouseHover == 1)) {
        /* Remplissage avec couleur survol */
        ChoisirCouleurDessin(pCase->hoverColor);
        RemplirRectangle(
                pCase->x + 1, pCase->y + 1,
                pCase->width - 1, pCase->height - 1);
    }
        /* Si quelqu'un dedans */
    else {
        /* Soit une croix soit un pion */
        if (pCase->whoIn == CASE_MODE_PAWN) {
            /* Dessin du pion */
            ChoisirCouleurDessin(pCase->playerColor);
            RemplirArc(
                    pCase->x + (int) barSize,
                    pCase->y + (int) barSize,
                    pCase->width - 2 * (int) barSize,
                    pCase->height - 2 * (int) barSize,
                    0, 360);
        }
        else if (pCase->whoIn == CASE_MODE_BLOCKED) {
            /* Dessin de la croix */
            ChoisirCouleurDessin(pCase->playerColor);

            /* Barre horizontale */
            RemplirRectangle(
                    pCase->x + (int) barSize,
                    pCase->y + (pCase->height - (int) barSize) / 2,
                    pCase->width - 2 * (int) barSize,
                    (int) barSize);

            /* Barre verticale */
            RemplirRectangle(
                    pCase->x + (pCase->width - (int) barSize) / 2,
                    pCase->y + (int) barSize,
                    (int) barSize,
                    pCase->height - 2 * (int) barSize);
        }
    }
}
