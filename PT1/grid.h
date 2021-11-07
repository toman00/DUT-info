/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Entête pour les fonctions sur la grille.
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

#ifndef GRID_H
#define GRID_H

/*------------*/
/* Inclusions */
/*------------*/
#include "cases.h"

/*---------------------------*/
/* Défintions des constantes */
/*---------------------------*/

/*----------------------------------*/
/* Structure qui définie une grille */
typedef struct grid typeGrid;
struct grid {
    typeCase **cases; /* Tableau de cases */
    int nbCases; /* Nombre de cases */
};

/*-------------------------*/
/* Prototypes de fonctions */
/*-------------------------*/
/* Fonction Initialisation des attributs de la grille.
 *  pGrid : Grille en cours.
 * Retour : Aucun.
 */
void InitGrid(typeGrid *pGrid);
/* Fonction qui dessine la grille.
 *  pGrid : Grille en cours.
 * Retour : Aucun.
 */
void DrawGrid(typeGrid *pGrid);
/* Fonction de recherche de case cliquée.
 *  pGrid : La grille.
 *  mouseX, mouseY : Coordonnées de la souris.
 *  pCaseX, pCaseY : Coordonnées de la case à mettre à jour.
 * Retour :
 *  1 si c'est à mis jour, 0 sinon.
 */
int GetCaseFromMouse(typeGrid *pGrid, int mouseX, int mouseY, int *pCaseX, int *pCaseY);
/* Fonction de libération mémoire de la grille.
 *  pGrid : La grille.
 * Retour : Aucun.
 */
void FreeGrid(typeGrid *pGrid);

#endif /* GRID_H */
