import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Rose {
    
    
    /**
    * @param args non-utilisé
    */
    public static void main(String[] args) {

    	// Fenetre
        JFrame fenetre = new JFrame("Rose");

        // Configurations de la fenêtre
    	
	    fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(400, 400));

        
        
	    // Rend visible la fenetre
	    fenetre.setVisible(true);
    }
}