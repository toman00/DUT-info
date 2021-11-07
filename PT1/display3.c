/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient le troisième écran.
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
#include "display3.h"
#include "buttons.h"

/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction qui permet de générer le 3ème écran.
 *  pWinPlayer : Joueur gagnent (NULL si aucun).
 * Retour :
 *  Action choisie par le joueur.
 */
int CreateDisplay3(typePlayer *pWinPlayer) {
    int i;
    char winnerStr[] = "Joueur 0 remporte la victoire !";
    int nbButtons = 3; /* Nombre de boutons à gérer */
    int activeBtn; /* 1 si bouton cliqué, 0 sinon */
    int action = ACTION_NONE; /* Action associée au bouton */

    /* Boutons rangés dans un tableau */
    typeButton tabBtns[] = {
            {PROP_BTN_MENU},
            {PROP_BTN_REPLAY},
            {PROP_BTN_QUIT_3}
    };

    /* Titre de la fenêtre */
    ChoisirCouleurDessin(COLOR_BLACK);
    ChoisirTitreFenetre("BLOCUS - RESULTATS");

    /* Efface l'ancien affichage */
    EffacerEcran(COLOR_BACK);

    /* Tant qu'aucune action n'est demandée */
    while (action == ACTION_NONE) {
        /* Titre "Résultats" */
        if (pWinPlayer != NULL) {
            /* Il y a un gagnant */
            sprintf(winnerStr, "Joueur %d remporte la victoire !", pWinPlayer->id+1);
            EcrireTexte(280, 62, winnerStr, 1);

            /* Couleur du joueur */
            ChoisirCouleurDessin(pWinPlayer->color);
            RemplirRectangle(255, 45, 20, 20);
        }
        else {
            /* Il n'y a pas de gagnant */
            sprintf(winnerStr, "Pas de gagnant !");
            EcrireTexte(320, 62, winnerStr, 1);
        }

        /* Pour tous les boutons disponibles */
        for (i = 0; i < nbButtons; ++i) {
            /* Dessiner le bouton */
            DrawButton(&tabBtns[i]);
        }

        /* Si clique souris */
        if (SourisCliquee()) {
            /* Pour tous les boutons disponibles */
            for (i = 0; i < nbButtons; ++i) {
                /* Test si souris au-dessus du bouton cliqué */
                activeBtn = TestInButton(&tabBtns[i], _X, _Y);
                if (activeBtn == 1) {
                    /* Bouton cliqué, on récupère l'action associée */
                    action = tabBtns[i].action;
                }
            }
        }

        /* On laisse un peu de temps au CPU */
        usleep(CPU_SLEEP);
    }

    /* Retourne l'action chosie */
    return action;
}
