/**
* @version 1.0
* @author Tomy Da Rocha
*/
public class grille {
 
  /**
  * @param args utilisée
  */
  public static void main(String[] args) {
    /* Déclaration du tableau */
    /* On initialise le tableau d'entier à 0 avec autant de cases
     * qu'il y a d'argument */
    int i, j;
    /* On transforme le 1er argument en entier (cast) */
    int taille = Integer.parseInt(args[0]);
    /* Pour changer de ligne */
    for (i = 0; i <= (taille * 2); ++i) {
        /* Pour afficher la ligne */
        for (j = 0; j < taille; ++j) {
            /*S'il doit print le haut ou le bas de la case */
            if (i % 2 == 0) {
                if (j == 0) {
                    System.out.print("+-+");
                }
                else {
                    System.out.print("-+");
                }
            }
            else { /* Sinon */
                if (j == 0) {
                    System.out.print("| |");
                }
                else {
                    System.out.print(" |");
                }
            }
        }
        System.out.println();
        j = 0;
    }

    
    
  }
}