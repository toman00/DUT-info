import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Gris extends Color {

    public Gris(int gray) {
        super(gray,gray,gray);
    }


    /**
    * @param args utilisée
    */
    public static void main(String[] args) {
        Gris gris = new Gris(50);

    	// Fenetre
        JFrame fenetre = new JFrame("Grisaille");

        // Configurations de la fenêtre
    	fenetre.setSize(500, 500);
	    fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(500, 500));
        JPanel test = new JPanel();
        test.setBackground(gris);
        fenetre.add(test);

        
	    // Rend visible la fenetre
	    fenetre.setVisible(true);
    }
}