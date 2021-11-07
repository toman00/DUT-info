/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient les fonctions sur les boutons.
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
#include "buttons.h"

/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction qui permet de tester si la position de la souris est sur le bouton.
 *  pBtn : Pointeur vers le bouton concerné.
 *  posX, posY : Coordonnées à tester.
 * Retour :
 *  1 si dans le bouton et 0 sinon.
 */
int TestInButton(typeButton *pBtn, int posX, int posY) {
    int inButton = 0; /* 1 si sur bouton, 0 sinon */

    /* Test si la position de la souris est dans le rectangle du bouton */
    /* Teste les X */
    if ((posX > pBtn->x) && (posX < (pBtn->x + pBtn->width))) {
        /* Coordonnée X dans la zone du bouton */
        /* Teste les Y */
        if ((posY > pBtn->y) && (posY < (pBtn->y + pBtn->height))) {
            /* Coordonnée Y dans la zone du bouton */
            inButton = 1;
        }
    }

    /* Retourne le résultat du test */
    return inButton;
}

/* Fonction qui permet de dessiner un bouton.
 *  pBtn : Pointeur vers le bouton concerné.
 * Retour : Aucun.
 */
void DrawButton(typeButton *pBtn) {
    int mouseHover = 0; /* 1 si souris sur un bouton */

    /* Pour calcul de position */
    /* On calcule la taille du texte : largeur + hauteur  + ajout de bordures */
    int widthText = TailleChaineEcran(pBtn->text, pBtn->textSize);
    /* Partie inférieure du texte */
    int infText = TailleInfPolice(pBtn->textSize);
    /* Partie supérieure du texte */
    int supText = TailleSupPolice(pBtn->textSize);
    int heightText = supText + infText;

    /* Récupération de la position de la souris */
    SourisPosition();

    /* Est-ce que la souris est au-dessus du bouton ? */
    mouseHover = TestInButton(pBtn, _X, _Y);

    /* Mise à jour de la largeur/hauteur du bouton */
    pBtn->width = widthText + 2*BTN_OFFSET_PIX;
    pBtn->height = heightText + 2*BTN_OFFSET_PIX;

    /* Dessin du rectangle */
    ChoisirCouleurDessin(pBtn->rectColor);
    DessinerRectangle(
        pBtn->x, pBtn->y,
        pBtn->width, pBtn->height);

    /* Remplir le rectangle avec la couleur hover/back */
    if (mouseHover == 0) {
        /* La souris n'est pas dessus */
        ChoisirCouleurDessin(pBtn->backColor);
    }
    else {
        /* La souris est au-dessus */
        ChoisirCouleurDessin(pBtn->hoverColor);
    }
    RemplirRectangle(
        pBtn->x + 1, pBtn->y + 1,
        pBtn->width - 1, pBtn->height - 1);

    /* Ecriture du texte */
    ChoisirCouleurDessin(pBtn->textColor);
    EcrireTexte(
    pBtn->x + BTN_OFFSET_PIX, pBtn->y + BTN_OFFSET_PIX + supText,
        pBtn->text, pBtn->textSize);
}
