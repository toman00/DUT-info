/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Entête pour les fonctions sur les cases.
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

#ifndef CASES_H
#define CASES_H

/*------------*/
/* Inclusions */
/*------------*/
#include <graph.h>

/*---------------------------*/
/* Défintions des constantes */
/*---------------------------*/
/* Qui est dans la case ? */
#define CASE_MODE_FREE    -1 /* Personne dedans, case libre */
#define CASE_MODE_PAWN    1  /* Joueur dedans (pion) */
#define CASE_MODE_BLOCKED 2  /* Case bloquée (croix) */

/*--------------------------------*/
/* Structure qui définie une case */
typedef struct structCase typeCase;
struct structCase {
    int x;              /* Position X de la case */
    int y;              /* Position Y de la case */
    int width;          /* Largeur de la case */
    int height;         /* Hauteur de la case */
    couleur rectColor;  /* Couleur du rectangle */
    couleur backColor;  /* Couleur du fond */
    couleur hoverColor; /* Couleur du survol */
    /* whoIn : Qui est dedans ?
     *  - CASE_MODE_FREE : Case libre.
     *  - CASE_MODE_PAWN : Pion.
     *  - CASE_MODE_BLOCKED : Croix.
     * */
    int whoIn;
    couleur playerColor; /* Couleur de l'occupant */
};

/*-------------------------*/
/* Prototypes de fonctions */
/*-------------------------*/
/* Fonction qui permet de tester si la position de souris est sur la case.
 *  pCase : Pointeur vers la case concernée.
 *  posX, posY : Coordonnées de la souris à tester.
 * Retour :
 *  1 si dans la case et 0 sinon.
 */
int TestInCase(typeCase *pCase, int posX, int posY);
/* Fonction de dessin de la case.
 *   pCase : Pointeur vers la case concernée.
 * Retour : Aucun.
 */
void DrawCase(typeCase *pCase);

#endif /* CASES_H */
