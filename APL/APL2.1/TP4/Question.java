import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Question {
    
    
    /**
    * @param args non-utilisé
    */
    public static void main(String[] args) {

    	// Fenetre
        JFrame fenetre = new JFrame("Question");

        // Configurations de la fenêtre
    	
	    fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(200, 200));

        // Question
        JLabel question = new JLabel("Aimez-vous les chiens ?");

        // Boutons
        JButton yes = new JButton("Oui");
        JButton no = new JButton("Non");
        JButton nspp = new JButton("NSPP");
        
        FlowLayout container = new FlowLayout(FlowLayout.CENTER);
        fenetre.setLayout(container);

        // Ajouts de panneaux 
        JPanel top = new JPanel();
        top.add(question);

        JPanel bottom = new JPanel();
        bottom.add(yes);
        bottom.add(no);
        bottom.add(nspp);
        // Ajouts dans la fenêtre
        fenetre.add(top);
        fenetre.add(bottom);

        
	    // Rend visible la fenetre
	    fenetre.setVisible(true);
    }
}