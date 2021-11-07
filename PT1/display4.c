/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient le dernier écran.
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
#include <unistd.h>
#include <graph.h>
/*------------------------------*/
/* Inclusions librairies projet */
/*------------------------------*/
#include "defines.h"
#include "display4.h"

/*-----------------------------*/
/* Définitions des constantess */
/*-----------------------------*/
/* Offsets en X et Y, pour l'offset d'affichage = bordure d'écrans */
#define LIMIT_OFFSET_X      10
#define LIMIT_OFFSET_Y      10
/* Incrémentation des positions X et Y */
#define INC_X               10
#define INC_Y               5
/* Vitesse de balayage => attente entre chaque affichage en microsecondes */
#define SCROLL_SPEED        100000
/* Couleur de texte pour les auteurs */
#define COLOR_AUTHORS       COLOR_BLACK
/* Taille du texte auteurs */
#define SIZE_AUTHORS        2

/* Fonction de calcul de taille de texte en pixels.
 *  pText : Texte concerné.
 *  textSize : Taille de police choisie.
 *  pWidth : Largeur mise à jour de texte en pixels.
 *  pHeight : Hauteur mise à jour de teexte en pixels.
 * Retour : Aucun.
 */
void CalculateTextSize(char *pText, int textSize, int *pWidth, int *pHeight) {
    /* On calcule la taille du texte : largeur + hauteur  + ajout de bordures */
    *pWidth = TailleChaineEcran(pText, textSize);
    /* Partie inférieure du texte */
    int infText = TailleInfPolice(textSize);
    /* Partie supérieure du texte */
    int supText = TailleSupPolice(textSize);
    *pHeight = supText + infText;
}

/* Fonction qui affiche l'écran de fin : défilement.
 * Le défilement s'arrête lorsqu'un clique de souris est détectée
 * Retour : Aucun.
 */
void CreateDisplay4() {
    int line = 0; /* Index de lignes dans le tableau à afficher */
    int lineWidth = 0; /* Largeur de ligne */
    int lineHeight = 0; /* Hauteur de ligne */
    int startY = LIMIT_OFFSET_Y; /* Position de départ d'écriture de la 1ère ligne en Y */
    int incY = INC_Y; /* Incrément de départ d'écriture en Y */
    int totalLinesHeight = 0; /* Hauteur totale de toutes les lignes */
    int mouseDetected = 0; /* 1 si souris cliquée, 0 sinon */

    /* Lignes de texte à écrire */
    char *authorsLines[] = {
        "Theo CHOLLET (chollet.theo@gmail.com)",
        "Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)",
        "Date : 15/01/2021",
        "Version 1.0"
    };

    /* Nombre de lignes dans le tableau */
    int nbLines = sizeof(authorsLines) / sizeof(authorsLines[0]);

    /* Tableau d'offsets en X pour chaque ligne */
    int *startX;
    startX = (int *) malloc(sizeof(int) * nbLines);
    /* Tableau d'incréments en X pour chaque ligne */
    int *incX;
    incX = (int *) malloc(sizeof(int) * nbLines);

    /* Initialisation pour toutes les lignes */
    for (line = 0; line < nbLines; ++line) {
        /* Hauteur de la ligne */
        CalculateTextSize(authorsLines[line], 2, &lineWidth, &lineHeight);
        /* Hauteur totale de toutes les lignes */
        totalLinesHeight += lineHeight;

        /* Offset X de chaque ligne */
        startX[line] = LIMIT_OFFSET_X;
        /* Incrément X de chaque ligne */
        incX[line] = INC_X;
    }

    /* Titre de la fenêtre */
    ChoisirTitreFenetre("BLOCUS - C'est fini !");

    /* Tant que l'on a pas cliqué */
    while (!mouseDetected) {
        /*---------------------------*/
        /* Efface l'ancien affichage */
        EffacerEcran(COLOR_BACK);

        /*------------------------*/
        /* Affichage des 3 lignes */
        /* Pour toutes les lignes à écrire */
        for (line = 0; line < nbLines; ++line) {
            /* Hauteur / largeur de la ligne */
            CalculateTextSize(authorsLines[line], 2, &lineWidth, &lineHeight);

            /* On imprime la ligne */
            ChoisirCouleurDessin(COLOR_AUTHORS);
            EcrireTexte(
                startX[line],
                startY + (line + 1) * lineHeight,
                authorsLines[line], SIZE_AUTHORS);
        }


        /* Passage à la position X de chaque ligne */
        for (line = 0; line < nbLines; ++line) {
            /* Hauteur / largeur de la ligne */
            CalculateTextSize(authorsLines[line], 2, &lineWidth, &lineHeight);

            /* Offset suivant X de la ligne */
            startX[line] += incX[line];
            

            /* Pour bouger la ligne de gauche à droite */
            /* Si fin d'écran en X (0 ou largeur) -> inversion de l'incrémentation */
            /* Test sur la droite et sur la gauche */
            if (((startX[line] + lineWidth + LIMIT_OFFSET_X) > SCREEN_X) ||
                (startX[line] < LIMIT_OFFSET_X)) {
                /* Inversion incrémentation */
                incX[line] = -incX[line];
                startX[line] += incX[line];
            }
        }

        /* Prochaine position Y */
        startY += incY;

        /* Si on part dans l'autre sens (bas -> haut) ou (haut -> bas) */
        /* Si fin d'écran en Y (0 ou hauteur) -> inversion de l'incrémentation */
        /* Test sur la bas et sur le haut */
        if (((startY + totalLinesHeight) > SCREEN_Y) ||
            (startY < LIMIT_OFFSET_Y)) {
            /* Inversion incrémentation */
            incY = -incY;
            startY += incY;
        }

        /* Attente avant le prochain affichage */
        usleep(SCROLL_SPEED);

        /* Si une souris est cliquée -> on arrête */
        mouseDetected = SourisCliquee();
    }

    /* Libération de la mémoire */
    free(startX);
    free(incX);
}
