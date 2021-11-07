/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Entête pour le deuxième écran.
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

#ifndef DISPLAY2_H
#define DISPLAY2_H

/*------------*/
/* Inclusions */
/*------------*/
/* Les joueurs */
#include "player.h"
/* Librairie defines */
#include "defines.h"

/*-------------------------*/
/* Prototypes de fonctions */
/*-------------------------*/
/* Fonction qui permet de générer le 2ème écran.
 *  gridSize : Taille de la grille.
 *  pPlayers : Tableau des joueurs.
 *  nbPlayers : Nombre de joueurs.
 * Retour :
 *  Index de joueur gagnant, ou -1 si aucun.
 * */
int CreateDisplay2(int gridSize, typePlayer *players, int nbPlayers);

#endif /* DISPLAY2_H */
