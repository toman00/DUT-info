/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Entête pour le troisième écran.
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

#ifndef DISPLAY3_H
#define DISPLAY3_H

/*------------*/
/* Inclusions */
/*------------*/
#include "player.h"

/*-------------------------*/
/* Prototypes de fonctions */
/*-------------------------*/
/* Fonction qui permet de générer le 3ème écran.
 *  pWinPlayer : Joueur gagnent (NULL si aucun).
 * Retour :
 *  Action choisie par le joueur.
 */
int CreateDisplay3(typePlayer *pWinPlayer);

#endif /* DISPLAY3_H */
