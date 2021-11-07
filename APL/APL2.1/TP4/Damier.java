import javax.swing.*;
import java.awt.*;

/**
* @version 2.0
* @author Tomy Da Rocha
*/
    
public class Damier {
    // Taille du damier
     private int taille = 9;
    /**
    * @param args non-utilisé
    */
    public static void main(String[] args) {
        Damier damier = new Damier();
    	// Fenetre
        JFrame fenetre = new JFrame("Damier");

        // Configurations de la fenêtre
    	fenetre.setSize(700, 700);
	    fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(500, 500));

        // Tableau qui contient chacune des cases
        JPanel[] panelArray = new JPanel[damier.taille*damier.taille];
        
        // Création de la grille
        GridLayout grille = new GridLayout(damier.taille,damier.taille);
        fenetre.setLayout(grille);
        
        for(int i = 0; i < damier.taille*damier.taille; i++) {
            panelArray[i] = new JPanel();
            
            /* 1 fois sur deux on change de couleur
             * afin de faire un damier */
            if (i % 2 == 0) {
                panelArray[i].setBackground(Color.WHITE);
            }
            else {
                panelArray[i].setBackground(Color.CYAN);
            }
            // Ajouts successifs des cases à la fenêtre
            fenetre.add(panelArray[i]);
        }
        
        
	    // Rend visible la fenetre
	    fenetre.setVisible(true);
    }
}