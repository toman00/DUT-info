/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Docu {
    private String[] array;


    /**
    * @param args utilisé
    */

    /* Méthode qui transforme tous les char. en miniscules en maj.
     * d'un tableau de String */
    public void upperCase() {
        String[] tab = this.array;

        int length = tab.length;
        String[] newTab = new String[length];
        // On recopie le tableau entier afin de ne pas 
        // modifier celui de départ
        for(int i = 0; i < length; i++) {
            newTab[i] = tab[i];
            // On convertit les minuscules en maj dans le nouveau tab.
            newTab[i] = newTab[i].toUpperCase();
            System.out.print(newTab[i] + ' ');
        }
    }

    /* Méthode qui convertit un entier de la base 8 à la base 16 */
    public void octToHex() {
        String[] tab = this.array;
        // Taille du tableau
        int length = tab.length;
        // Duplication du tableau pour ne pas le changer
        int[] newTab = new int[length];
        // Tableau de String pour afficher en Hexa
        String[] finalTab = new String[length];

        for(int i = 0; i < length; i++) {
            // on attribue chaque valeur au nouveau tab
            // et on le convertit en un entier de base 8
            newTab[i] = Integer.valueOf(tab[i], 8);
            // Ensuite on le convertit en base 16
            finalTab[i] = Integer.toHexString(newTab[i]);
            // Affiche le résultat
            this.arrayChange(finalTab);
            this.upperCase();
        }
    }

    public void arrayChange(String[] array) {
        this.array = array;
    }

    public static void main(String[] args) {
        Docu docu = new Docu();
        
        // On utilisera les arguments en ligne de comm. en entrée
        docu.arrayChange(args);
        docu.octToHex();
    }
}
