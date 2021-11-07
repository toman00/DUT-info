/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Contient le deuxième écran.
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
#include <time.h>
#include <graph.h>
/*------------------------------*/
/* Inclusions librairies projet */
/*------------------------------*/
#include "display2.h"
#include "buttons.h"
#include "player.h"

/*---------------------------*/
/* Déclaration des fonctions */
/*---------------------------*/
/* Fonction qui affiche la fin du jeu.
 * Retour : Aucun.
 */
void DisplayEndGame() {
    /* Affiche un rectangle derrière le texte */
    ChoisirCouleurDessin(COLOR_LIGHT_BLUE);
    RemplirRectangle(230,150,400,80);

    /* Affiche un rectangle non-plein autour de celui
     * précédemment remplit */
    ChoisirCouleurDessin(COLOR_BLACK);
    DessinerRectangle(230,150,400,80);
    /* Affiche un texte si la partie est finie */
    ChoisirCouleurDessin(COLOR_RED);
    EcrireTexte(
        250, 200,
        "Il est l'heure des resultats", 2);
}

/* Fonction qui permet d'afficher le joueur en cours.
 *  pPlayer : Joueur en à afficher.
 * Retour : aucun.
 */
void DisplayPlayerRound(typePlayer *pPlayer) {
    /* Nom du joueur */
    char playerName[] = "Joueur X - Placement   ";
    char playerType[] = "Joueur ";

    /* Efface l'ancien */
    ChoisirCouleurDessin(COLOR_BACK);
    RemplirRectangle(500, 80, 200, 30);

    /* Affiche le nouveau */
    ChoisirCouleurDessin(COLOR_BLACK);

    /* Si IA */
    if (pPlayer->type == TYPE_PLAYER_IA) {
        sprintf(playerType, "CPU");
    }
    /* Si humain */
    else {
        sprintf(playerType, "Joueur");
    }

    /* Si placé = 0 -> demande de placement */
    if (pPlayer->placed == 0) {
        sprintf(playerName, "%s %d - Placement", playerType, pPlayer->id+1);
    }
    /* Si placé = 1 et blocked = 0 -> Demande de blocage */
    else if ((pPlayer->placed == 1) && (pPlayer->blocked == 0)) {
        sprintf(playerName, "%s %d - Blocage", playerType, pPlayer->id+1);
    }

    /* Ecriture du texte */
    EcrireTexte(500, 100, playerName, 1);

    /* Dessin du carré du joueur (avec sa couleur) */
    ChoisirCouleurDessin(pPlayer->color);
    RemplirRectangle(475, 82, 20, 20);
}

/* Fonction qui gère le tour de chaque joueur.
 *  pPlayers : Tableau des joueurs.
 *  pGrid : La grille.
 *  round : Le joueur actuel.
 *  nbPlayers : Nombre de joueurs.
 *  pQuitBtn : Le bouton quitter.
 * Retour :
 *  1 si bouton Quitter cliqué, 0 sinon.
 */
int ManagePlayer(typePlayer *pPlayers, typeGrid *pGrid, int round, int nbPlayers, typeButton *pQuitBtn) {
    /* 1 Joueur placé / bloqué, 0 sinon, utile pour l'IA et le temps d'attente uniquement */
    int playerPlaced = 0;
    int quitBtnClic = 0; /* 1 si bouton Quitter cliqué, 0 sinon */
    int idOther = 0; /* Identifiant du joueur suivant */

    /* Position du joueur dans la case */
    int playerX = DEFAULT_POS_NONE; /* Position case X du joueur */
    int playerY = DEFAULT_POS_NONE; /* Position case Y du joueur */

    /* C'est au tour de : ... */
    DisplayPlayerRound(&pPlayers[round]);

    /* Récupérer les coordonnées (playerX, playerY) :
    *  Humain : cliquées
    *  IA : générées */
    if (pPlayers[round].type == TYPE_PLAYER_IA) {
        /* Initialisation du random */
        srand(clock());

        /* Joueur non placé */
        if (pPlayers[round].placed == 0) {
            /* Récupération d'une case au hasard */
            GetIAFreeCases(&pPlayers[round], pGrid, &playerX, &playerY);
        }
        /* Si joueur placé et non bloqué */
        else if ((pPlayers[round].placed == 1) && (pPlayers[round].blocked == 0)) {
            /* Récupération de l'index du joueur au hasard */
            idOther = rand() % nbPlayers;
            /* Tant que c'est lui-même : on redemande un autre index */
            while (idOther == round) {
                idOther = rand() % nbPlayers;
            }
            /* Récupération d'une case au hasard */
            if (GetFreeCases(&pPlayers[idOther], pGrid) != 0) {
                /* Il y a des cases libres, on prend autour de l'humain */
                GetIAFreeCases(&pPlayers[idOther], pGrid, &playerX, &playerY);
            }
            else {
                /* L'IA a forcément gagné */
                pPlayers[round].blocked = 1;
            }
        }
    } /* if (pPlayers[round].type == TYPE_PLAYER_IA) */

    /* Si clic souris */
    if (SourisCliquee()) {
        /* Obligés de gérer le clique souris dans un seul endroit */
        /* Si bouton quitter cliqué */
        quitBtnClic = TestInButton(pQuitBtn, _X, _Y);

        /* Coordonnées de placement/blocage */
        GetCaseFromMouse(pGrid, _X, _Y, &playerX, &playerY);
    }

    /*--------------------------*/
    /* Partie placement/blocage */
    playerPlaced = PlacePlayer(&pPlayers[round], pGrid, playerX, playerY);

    /* Légère attente avant de passer à l'action suivante
     * seulement si le joueur est IA et placé */
    if ((pPlayers[round].type == TYPE_PLAYER_IA) && (playerPlaced == 1)) {
        usleep(IA_SLEEP);
    }

    /* Retourne l'état du clique sur Quitter */
    return quitBtnClic;
}

/* Fonction qui permet de générer le 2ème écran.
 *  gridSize : Taille de la grille.
 *  pPlayers : Tableau des joueurs.
 *  nbPlayers : Nombre de joueurs.
 * Retour :
 *  Index de joueur gagnant, ou -1 si aucun.
 */
int CreateDisplay2(int gridSize, typePlayer *pPlayers, int nbPlayers) {
    int i;
    int quitBtnClic = 0; /* 1 si appui sur bouton quitter */
    int round = 0; /* On commence par le joueur 0 (humain) */
    int nbFreeCases = gridSize * gridSize; /* Nombre de cases libres */
    int changePlayer = 0; /* 1 si changement de joueur demandé, 0 sinon */
    int winner = -1; /* -1 = pas de gagnant, sinon index du joueur */

    /* Grille de jeu */
    typeGrid playGrid;
    /* Réglage de la taille */
    playGrid.nbCases = gridSize;

    /* Titre de la fenêtre */
    ChoisirTitreFenetre("BLOCUS - PARTIE EN COURS");

    /* Efface le contenu actuel */
    EffacerEcran(COLOR_BACK);

    /* Un 2ème bouton "Quitter" */
    typeButton quitBtn2 = {PROP_BTN_QUIT_2};

    /* Initialisation de la grille */
    InitGrid(&playGrid);

    /* Initialisation de la position des joueurs */
    for (i = 0; i < nbPlayers; ++i) {
        pPlayers[i].gridX = DEFAULT_POS_NONE;
        pPlayers[i].gridY = DEFAULT_POS_NONE;
        pPlayers[i].roundCount = 0;
        pPlayers[i].placed = 0;
        pPlayers[i].blocked = 0;
    }

    /*---------------------------------*/
    /* Tant qu'il y a des cases libres :
     *  - Teste si arrêt de la boucle
     *  - Affiche la grille
     *  - Teste la position des joueurs
     *---------------------------------*/
    while (nbFreeCases != 0) {
        /* Titre 2ème section */
        ChoisirCouleurDessin(COLOR_BLACK);
        EcrireTexte(500,50, "C'est au tour de :",1);

        /* Dessine le bouton quitter */
        DrawButton(&quitBtn2);

        /* Affiche la grille */
        DrawGrid(&playGrid);

        /* On s'arrête quand il n'y a plus de déplacement possible */
        /* Teste si le joueur actuel est placé (ce n'est pas  le premier tour) */
        if (pPlayers[round].roundCount != 0) {
            /* Le joueur est placé, on teste le nombre de cases */
            nbFreeCases = GetFreeCases(&pPlayers[round], &playGrid);
        }

        /*---------------------*/
        /* Gestion des joueurs */
        /*---------------------*/
        quitBtnClic = ManagePlayer(pPlayers, &playGrid, round, nbPlayers, &quitBtn2);
        if (quitBtnClic) {
            /* Quitter la partie */
            break;
        }

        /*-----------------------------*/
        /* Partie changement de joueur */
        /* Si joueur placé et qu'il a bloqué une case  : on passe au suivant */
        /* Si 1er tour -> Placement puis changement de joueur
         * Sinon Placement puis blocage puis changement de joueur */
        if (pPlayers[round].placed == 1) {
            /* Le joueur est placé */
            /* 1er tour ou joueur bloqué ? */
            if ((pPlayers[round].roundCount == 0) ||
                (pPlayers[round].blocked == 1)) {
                /* Demande de changement de joueur */
                changePlayer = 1;

            }
        }

        /* Si demande de changement de tour */
        if (changePlayer == 1) {
            /* Incrémentation du nombre de tours de jeu */
            pPlayers[round].roundCount += 1;
            /* Remise à zéro des indicateurs de placement / blocage du joueur */
            pPlayers[round].placed = 0;
            pPlayers[round].blocked = 0;

            /* Joueur suivant */
            round += 1;
            round = round % nbPlayers;

            /* Plus de demande de changement de tour */
            changePlayer = 0;
        }

        /* On laisse un peu de temps au CPU */
        usleep(CPU_SLEEP);
    } /* while (nbFreeCases != 0) */

    /* Si on n'a pas demandé de quitter */
    if (quitBtnClic == 0) {
        /* Affichage partie finie */
        DisplayEndGame();

        /* Attente avant changement d'écran */
        sleep(WIN_SLEEP);

        /* Retourne le gagnant :
         * le joueur d'avant la fin de la boucle */
        winner = abs((round - 1) % nbPlayers);
    }

    /* Libération mémoire de la grille */
    FreeGrid(&playGrid);

    /* Retourne l'index du gagnant */
    return winner;
}
