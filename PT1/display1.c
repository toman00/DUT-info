/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient le premier écran.
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
#include "display1.h"
#include "buttons.h"

/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction qui permet de mettre à jour la taille de la grille (Compteur).
 *  gridSize : Taille de la grille.
 * Retour : Aucun.
 */
void DisplayGridSize(int gridSize) {
    /* Chaine de caracteres contenant le nombre à afficher */
    char strGridSize[2];
    sprintf(strGridSize, "%d", gridSize);

    /* Choix de la couleur */
    ChoisirCouleurDessin(COLOR_BACK);

    /* Dessin du rectangle d'effacement */
    int widthText = TailleChaineEcran(strGridSize, 2);
    int heightText = TailleInfPolice(2) + TailleSupPolice(2);
    RemplirRectangle(375, 380 - heightText, widthText, heightText);

    /* Choix de la couleur du texte */
    ChoisirCouleurDessin(COLOR_BLACK);

    /* Affichage sur fenêtre */
    EcrireTexte(375, 380, strGridSize, 2);
}

/* Fonction qui permet de créer le 1er écran
 *  pGridSize : Taille de la grille qui sera réglée par le joueur.
 * Retour :
 *  Action (bouton cliqué).
 */
int CreateDisplay1(int *pGridSize) {
    int i;
    int activeBtn; /* 1 si bouton cliqué, 0 sinon */
    int action = ACTION_NONE; /* Action demandée par le clique */
    int nbButtons = 6; /* Nombre de boutons à utiliser sur la fenêtre */

    /* Boutons rangés dans un tableau */
    typeButton tabBtns[] = {
        {PROP_BTN_QUIT},
        {PROP_BTN_SUB},
        {PROP_BTN_ADD},
        {PROP_BTN_1_PLAYER},
        {PROP_BTN_2_PLAYERS},
        {PROP_BTN_2_IA}
    };

    /* Titre de la fenêtre */
    ChoisirTitreFenetre("BLOCUS - MENU PRINCIPAL");
    EffacerEcran(COLOR_BACK);

    /*-----------------------------------------
     * Gestion des actions de l'utilisateur :
     *  - Clique sur +/-
     *  - Clique sur 1 Joueur / 2 Joueurs
     *  - Clique sur Quitter
     *---------------------------------------*/
    while (action == ACTION_NONE) {
        /*---------------------------------------*/
        /* Dessiner tous les boutons disponibles */
        for (i = 0; i < nbButtons; ++i) {
            DrawButton(&tabBtns[i]);
        }

        /* Textes */
        /* Titre 1ère section */
        EcrireTexte(300,50, "Menu Principal",2);
        /* Titre 2ème section */
        EcrireTexte(277,275, "Taille de la grille",2);

        /* Mise à jour du compteur */
        DisplayGridSize(*pGridSize);

        /*------------------*/
        /* Si clique souris */
        if (SourisCliquee()) {
            /* Pour tous les boutons disponibles */
            for (i = 0; i < nbButtons; ++i) {
                /* Test si souris au-dessus du bouton cliqué */
                activeBtn = TestInButton(&tabBtns[i], _X, _Y);
                if (activeBtn == 1) {
                    /* Bouton cliqué, on récupère l'action associée */
                    action = tabBtns[i].action;

                    /* Si bouton "-" */
                    if (action == ACTION_SUB) {
                        /* Décrémente la taille de la grille */
                        *pGridSize -= 1;
                        if (*pGridSize < GRID_MIN_SIZE) {
                            *pGridSize = GRID_MIN_SIZE;
                        }

                        /* Affichage du compteur de taille de grille */
                        DisplayGridSize(*pGridSize);

                        /* Reset action : on ne sort pas de la boucle clique souris */
                        action = ACTION_NONE;
                    }

                    /* Si bouton "+" */
                    else if (action == ACTION_ADD) {
                        /* Incrémente la taille de la grille */
                        *pGridSize += 1;
                        if (*pGridSize > GRID_MAX_SIZE) {
                            *pGridSize = GRID_MAX_SIZE;
                        }

                        /* Affichage du compteur de taille de grille */
                        DisplayGridSize(*pGridSize);

                        /* Reset action : on ne sort pas de la boucle clique souris */
                        action = ACTION_NONE;
                    }
                }
            } /* for (i = 0; (i < nbButtons) && (activeBtn == 0); ++i) */
        } /* if (SourisCliquee()) */

        /* On laisse un peu de temps au CPU */
        usleep(CPU_SLEEP);
    } /* while (action == ACTION_NONE) */

    /* Retourne l'action chosie */
    return action;
}
