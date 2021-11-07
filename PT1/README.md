# PT1

## Premier projet tutoré réalisé en C.

Jeu vidéo en tour par tour, développé en collaboration avec Théo CHOLLET. Le jeu consiste à choisir une case où se placer, puis rendre une autre case inaccessible définitivement pour les deux joueurs. Le premier étant bloqué à perdu. Étant un projet scolaire, les règles étaient d'utiliser la bibliothèque graphique de l'IUT de Fontainebleau, et de réaliser 3 écrans. Le premier écran sert à définir les options de la partie (voir captures d'écrans), avec une grille de 3x3 à 9x9. Le bouton quitter sert à fermer la fenêtre. Enfin, cliquer sur 1 ou 2 joueur(s) lancera la partie.
La partie en mode 1 joueur remplacera le second joueur par une intelligence artificielle. Cette dernière se placera dans une case vide aléatoirement, puis ces déplacements le seront aussi tout en restant dans sa portée (1 case, diagonale possible). Le choix de la case à condamner se fait également de façon alétoire, mais autour du joueur humain, afin de le bloquer plus rapidement éventuellement. Cela rajoute du sens au jeu de l'I.A et augmente la difficulté.

La partie commence en demandant au joueur 1 de se placer, il choisira la case qu'il veut condamner si elle est libre. Le tour passera au joueur 2 si c'est le cas et ainsi de suite.

Le troisième et dernier écran affiche le gagnant, et propose au(x) joueur(s) de recommencer une partie (avec les mêmes paramètres), de revenir au menu principal (écran 1) ou bien de quitter le jeu (ferme la fenêtre). 