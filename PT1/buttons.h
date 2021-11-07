/*-----------------------------------------------
 * Projet : Projet Tutoré 1.1 - Blocus
 * Description :
 *   Entête pour les fonctions sur les boutons.
 * Auteurs :
 *   - Théo CHOLLET (chollet.theo@gmail.com)
 *   - Tomy DA ROCHA (tomy.da-rocha@etu.u-pec.fr)
 * Date : 27/12/2020
 ----------------------------------------------*/

#ifndef BUTTONS_H
#define BUTTONS_H

/*------------*/
/* Inclusions */
/*------------*/
#include <graph.h>
#include "defines.h"

/*---------------------------*/
/* Défintions des constantes */
/*---------------------------*/
/* Couleurs pour les boutons */
#define BTN_TEXT_COLOR      COLOR_BLACK
#define BTN_RECT_COLOR      COLOR_BLACK
#define BTN_BACK_COLOR      COLOR_LIGHT_BLUE
#define BTN_HOVER_COLOR     COLOR_BLUE

/* Propriétés des boutons : [X, Y, text, textSize, textColor, rectColor, backColor, overColor, action] */
/* Ecran 1 */
#define PROP_BTN_QUIT       346, 150, "Quitter", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_QUIT
#define PROP_BTN_1_PLAYER   255, 100, "1 Joueur", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_1_PLAYER
#define PROP_BTN_2_PLAYERS  398, 100, "2 Joueurs", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_2_PLAYERS
#define PROP_BTN_SUB        320, 350, "-", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_SUB
#define PROP_BTN_ADD        430, 350, "+", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_ADD
#define PROP_BTN_2_IA       800, 500, "IA vs IA", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_2_IA
/* Ecran 2 */
#define PROP_BTN_QUIT_2     600, 400, "Quitter", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_QUIT
/* Ecran 3 */
#define PROP_BTN_MENU       353, 233, "Menu", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_MENU
#define PROP_BTN_REPLAY     338, 144, "Rejouer", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_REPLAY
#define PROP_BTN_QUIT_3     600, 400, "Quitter", 2, BTN_TEXT_COLOR, BTN_RECT_COLOR, BTN_BACK_COLOR, BTN_HOVER_COLOR, ACTION_QUIT

/* Décalage des pixels du rectangle par rapport au texte */
#define BTN_OFFSET_PIX      5

/*---------------------------------*/
/* Structure qui définie un bouton */
typedef struct button typeButton;
struct button {
    int x;              /* Position X du bouton */
    int y;              /* Position Y du bouton */
    char* text;         /* Texte du bouton */
    int textSize;       /* Taille du texte */
    couleur textColor;  /* Couleur du texte */
    couleur rectColor;  /* Couleur du rectangle autour */
    couleur backColor;  /* Couleur de fond */
    couleur hoverColor; /* Couleur si survol souris */
    int action;         /* Action du bouton */
    /* Paramètres calculés */
    int width;          /* Largeur du bouton */
    int height;         /* Hauteur du bouton */
};

/*-------------------------*/
/* Prototypes de fonctions */
/*-------------------------*/
void DrawButton(typeButton *pBtn);
int TestInButton(typeButton *pBtn, int posX, int posY);

#endif /* BUTTONS_H */
