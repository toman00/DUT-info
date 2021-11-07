/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Entête pour les définitions communes.
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

#ifndef DEFINES_H
#define DEFINES_H

/*------------*/
/* Inclusions */
/*------------*/
#include <graph.h>

/*---------------------------*/
/* Défintions des constantes */
/*---------------------------*/
/* Temps de repos CPU, en microsecondes */
#define CPU_SLEEP           2000

/* Temps d'attente pour l'IA, en microsecondes */
#define IA_SLEEP            500000

/* Temps d'attente quand un joueur a gagné, en secondes */
#define WIN_SLEEP           3

/* Tailles de fenêtre */
#define SCREEN_X            800
#define SCREEN_Y            500

/* Nombre de cases de la grille */
#define GRID_MIN_SIZE       3
#define GRID_MAX_SIZE       9
/* Taille en pixel de la grille */
#define GRID_PIXELS_SIZE    SCREEN_X / 2

/*----------*/
/* Couleurs */
/*----------*/
/* Couleur de fond */
#define COLOR_BACK          CouleurParComposante(171, 215, 235)
/* Couleurs utilisées */
#define COLOR_BLUE          CouleurParComposante(140, 175, 191)
#define COLOR_LIGHT_BLUE    CouleurParComposante(167, 188, 246)
#define COLOR_ORANGE        CouleurParComposante(255, 165, 0)
#define COLOR_RED           CouleurParComposante(214, 48, 35)
#define COLOR_BLACK         CouleurParComposante(0, 0, 0)

/* Couleurs de survol des boutons et des cases */
#define COLOR_BTN_OVER      CouleurParComposante(255, 165, 0)
#define COLOR_CASE_OVER     CouleurParComposante(253, 235, 211)

/* Actions associées aux boutons */
#define ACTION_NONE         0 /* Aucune */
#define ACTION_QUIT         1 /* Quitter */
#define ACTION_SUB          2 /* Décrémentation */
#define ACTION_ADD          3 /* Incrémentation */
#define ACTION_1_PLAYER     4 /* 1 Joueur */
#define ACTION_2_PLAYERS    5 /* 2 Joueurs */
#define ACTION_2_IA         6 /* 2 IAs */
#define ACTION_REPLAY       7 /* Rejouer */
#define ACTION_MENU         8 /* Menu */

#endif /* DEFINES_H */
