import java.util.Arrays;
/**
* @version 1.0
* @author Tomy Da Rocha
*/
public class tri {
 
  /**
  * @param args utilisée
  */
  public static void main(String[] args) {
    /* Déclaration du tableau */
    /* On initialise le tableau d'entier à 0 avec autant de cases
     * qu'il y a d'argument */
    int[] sorted = new int[args.length];
    int i = 1;
    /* Cast chacune des valeurs pour les transformer en entier */
    for (i = 0; i < sorted.length; ++i) {
        sorted[i] = Integer.parseInt(args[i]);
    }
    /* On trie par ordre croissant le tableau */
    Arrays.sort(sorted);
    /* On refait la même boucle afin d'afficher le tableau en entier */
    for (i = 0; i < sorted.length; ++i) {
        System.out.println(sorted[i]);
    }
  }
}