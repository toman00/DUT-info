// 
import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Boutons {
     
    /**
    * @param args non-utilisé
    */
    public static void main(String[] args) {
    	// Fenetre
    	JFrame fenetre = new JFrame();
    	// boutons
    	JButton button1 = new JButton("test1");
    	JButton button2 = new JButton("test2");
    	JButton button3 = new JButton("test3");
    	JButton button4 = new JButton("test4");
    	JButton button5 = new JButton("test5");
    	// Configurations
    	fenetre.setSize(500, 300);
	    fenetre.setLocation(110, 110);
	    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	    // Boutons
	    fenetre.add(button1);
	    fenetre.add(button2);

	    // Affichage boutons
	    fenetre.add(button1, BorderLayout.SOUTH);
	    fenetre.add(button2, BorderLayout.NORTH);
	    fenetre.add(button3, BorderLayout.CENTER);
	    fenetre.add(button4, BorderLayout.EAST);
	    fenetre.add(button5, BorderLayout.WEST);

	    // Rend visible la fenetre
	    fenetre.setVisible(true);
    }
}