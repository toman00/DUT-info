/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Entête pour les fonctions sur les joueurs.
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

#ifndef PLAYER_H
#define PLAYER_H

/*------------*/
/* Inclusions */
/*------------*/
#include <graph.h>
#include "grid.h"
#include "defines.h"

/*---------------------------*/
/* Défintions des constantes */
/*---------------------------*/
/* Constantes de couleurs pour les joueurs */
#define PLAYER_1_COLOR          COLOR_ORANGE
#define PLAYER_2_COLOR          COLOR_RED

/* Type de joueur */
#define TYPE_PLAYER_IA          0 /* IA */
#define TYPE_PLAYER_HUMAN       1 /* Humain */
/* Position par défaut : aucune */
#define DEFAULT_POS_NONE        -1

/* Nombre de joueurs */
#define NB_PLAYERS              13

/*------------------------------------*/
/* Structure qui représente un joueur */
typedef struct player typePlayer;
struct player {
    int type;       /* TYPE_PLAYER_HUMAN si humain, TYPE_PLAYER_IA si IA */
    int gridX;      /* Position X dans la grille */
    int gridY;      /* Position Y dans la grille */
    couleur color;  /* Couleur du joueur */
    int id;         /* Identifiant unique du joueur */
    int roundCount; /* Compteur de tours de joueur */
    int placed;     /* 1 si le joueur est placé, 0 sinon */
    int blocked;    /* 1 si le joueur a bloqué une case, 0 sinon */
};

/*-------------------------*/
/* Prototypes de fonctions */
/*-------------------------*/
/* Fonction qui calcule le nombre de cases disponibles pour un joueur.
 * pPlayer : Le joueur courant.
 * pGrid : La grille.
 * Retour :
 *  Nombre de cases disponibles.
 */
int GetFreeCases(typePlayer *pPlayer, typeGrid *pGrid);
/* Fonction de recherche de cases aléatoires par l'IA.
 *  pPlayer : Le joueur courant.
 *  pGrid : La grille.
 *  pPlayerX : La case X trouvée.
 *  pPlayerY : La case Y trouvée.
 * Retour : Aucun.
 */
void GetIAFreeCases(typePlayer *pPlayer, typeGrid *pGrid, int *pPlayerX, int *pPlayerY);
/* Fonction de placement d'un joueur.
 *  pPlayer : Le joueur en cours.
 *  playGrid : La grille de jeu.
 *  posX : Position X de la case.
 *  posY : Position Y de la case.
 * Retour :
 *  1 si placé, 0 sinon.
 */
int PlacePlayer(typePlayer *pPlayer, typeGrid *pGrid, int posX, int posY);

#endif /* PLAYER_H */
