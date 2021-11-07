/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Programme principal (main).
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
#include <time.h>
/*------------------------------*/
/* Inclusions librairies projet */
/*------------------------------*/
#include "display1.h"
#include "display2.h"
#include "display3.h"
#include "display4.h"

/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction d'initialisation de la liste des joueurs
 *  pPlayers : Liste de joueurs.
 * Retour : Aucun.
 **/
void InitPlayersList(typePlayer *pPlayers) {
    int i;

    /* Couleur aléatoire */
    srand(clock());

    /* Initialisation des joueurs */
    for (i = 0; i < NB_PLAYERS; ++i) {
        /* Identifiant de joueur */
        pPlayers[i].type = TYPE_PLAYER_IA;
        pPlayers[i].gridX = DEFAULT_POS_NONE;
        pPlayers[i].gridY = DEFAULT_POS_NONE;
        pPlayers[i].color = CouleurParComposante(
            rand() % 255, rand() % 255, rand() % 255);
        pPlayers[i].id = i;
        pPlayers[i].roundCount = 0;
        pPlayers[i].placed = 0;
        pPlayers[i].blocked = 0;
    }
}

/* Fonction principale du jeu.
 * Retour :
 *  EXIT_FAILURE si erreur, EXIT_SUCCESS si ok.
 */
int main(int argc, char* argv[]) {
    int i;
    int nbPlayers = 0; /* Nombre de joueurs (Max NB_PLAYERS) */

    /* Actions */
    int action1; /* Action de l'écran 1 */
    int action3 = ACTION_MENU; /* Action de l'écran 3 */
    int winner = -1; /* Index du joueur gagnant, -1 si aucun */
    int gridSize = GRID_MIN_SIZE; /* Taille de la grille */
    int play = 1; /* 1 si le joueur veut toujours jouer */

    /*--------------------*/
    /* Tableau de joueurs */
    typePlayer players[NB_PLAYERS];
    /* Initialisation des joueurs */
    InitPlayersList(players);

    /*------------------------*/
    /* Création de la fenêtre */
    if (InitialiserGraphique() == 0) {
        printf("Erreur d'initialisation Graphique !");
        return EXIT_FAILURE;
    }

    /* Taille de la fenêtre */
    CreerFenetre(10, 10, SCREEN_X, SCREEN_Y);

    /* Tant que l'on veut jouer */
    while (play == 1) {
        /*----------------------------------------*/
        /* Réglages préliminaires sur les joueurs */
        /* Initialisation des joueurs */
        InitPlayersList(players);
        /* Remise à zero des couleurs des 2 premiers joueurs */
        players[0].color = PLAYER_1_COLOR;
        players[1].color = PLAYER_2_COLOR;

        /* Taille de la grille */
        gridSize = GRID_MIN_SIZE;

        /* Générer le 1er écran : paramètres du jeu */
        action1 = CreateDisplay1(&gridSize);

        /*--------------------------------*/
        /* Si bouton 1 Joueur alors -> IA */
        if (action1 == ACTION_1_PLAYER) {
            /* Player 1 = Humain */
            players[0].type = TYPE_PLAYER_HUMAN;
            /* Player 2 = IA */
            players[1].type = TYPE_PLAYER_IA;
            /* Nombre de joueurs */
            nbPlayers = 2;
        }

        /*---------------------*/
        /* Si bouton 2 Joueurs */
        if (action1 == ACTION_2_PLAYERS) {
            /* Player 1 = Humain */
            players[0].type = TYPE_PLAYER_HUMAN;
            /* Player 2 = HUMAIN */
            players[1].type = TYPE_PLAYER_HUMAN;
            nbPlayers = 2;
        }

        /*--------------------*/
        /* Si bouton Magique ! */
        if (action1 == ACTION_2_IA) {
            /* IAsssss ! */
            for (i = 0; i < NB_PLAYERS; ++i) {
                players[i].type = TYPE_PLAYER_IA;
            }

            /* Nombre de joueurs maximal */
            nbPlayers = NB_PLAYERS;

            /* Taille de grille = nombre de joueurs */
            gridSize = NB_PLAYERS;
        }

        /*------------------------------------*/
        /* Si quitter sur écran 1 --> on sort */
        if (action1 == ACTION_QUIT) {
            play = 0;
        } else {
            /* Lancement de l'écran 2 */
            action3 = ACTION_REPLAY;
            while (action3 == ACTION_REPLAY) {
                /* 2ème partie de l'écran (Option de partie) */
                winner = CreateDisplay2(gridSize, players, nbPlayers);

                /* Générer le dernier écran */
                if (winner != -1) {
                    /* Un gagnant */
                    action3 = CreateDisplay3(&players[winner]);
                }
                else {
                    /* Pas de gagnant */
                    action3 = CreateDisplay3(NULL);
                }

                /* Si le joueur veut quitter */
                if (action3 == ACTION_QUIT) {
                    play = 0;
                }
            } /* while (action3 == ACTION_REPLAY) */
        }
    } /* while (play == 1) */

    /* Fenêtre de fermeture */
    CreateDisplay4();

    /* Ferme la fenêtre graphique */
    FermerGraphique();

    /* Succès */
    return EXIT_SUCCESS;
}