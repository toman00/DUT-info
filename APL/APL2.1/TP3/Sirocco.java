// 
import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/

    
public class Sirocco {

    /**
    * @param args 
    */
    public static void main(String[] args) {
   		// Fenetre
    	JFrame fenetre = new JFrame();
    	// Configurations
    	fenetre.setSize(500, 300);
	    fenetre.setLocation(0, 0);
	    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    // Affiche et config texte
	    JLabel siro = new JLabel("Sirocco");
	    siro.setHorizontalAlignment(JLabel.RIGHT);
	    fenetre.add(siro, BorderLayout.SOUTH);
	    // Rend visible la fenetre
	    fenetre.setVisible(true);
    }
}