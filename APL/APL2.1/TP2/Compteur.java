/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Compteur {
    // attribut
    private int compte;
    // méthode
    public void plusUn() {
        this.compte++;
    }
    // autre méthode
    public String toString() {
        return Integer.toBinaryString(this.compte);
    }

 
    /**
    * @param args utilisée
    */
    public static void main(String[] args) {
        /* on appelle la classe compteur, appelé ici c. */
        Compteur c = new Compteur();
        /* On met l'attribut compte à 5 sans y toucher directement */
        while (c.compte < 5) {
            c.plusUn();
        }
        /* On affiche les valeurs en binaires de 5 à 9 */
        while (c.compte <= 9) {
            /* Affiche en binaire le compteur actuel */
            System.out.println(c.toString());
            /* On incrémente */
            c.plusUn();
        }
    }
}