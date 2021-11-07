import javax.swing.*;
import java.awt.*;

/**
* @version 2.0
* @author Tomy Da Rocha
*/
    
public class Choix {
     
    /**
    * @param args non-utilisé
    */
    public static void main(String[] args) {
    	// Fenetre
        JFrame fenetre = new JFrame("Choix");
        
        // Configurations de la fenêtre
        fenetre.setSize(400, 150);
        fenetre.setMinimumSize(new Dimension(400, 150));
	    fenetre.setLocation(110, 110);
	    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        
    
    	// boutons
        JRadioButton gryffondor = new JRadioButton("Gryffondor");
        JRadioButton serdaigle = new JRadioButton("Serdaigle");
        JRadioButton serpentard = new JRadioButton("Serpentard");
        JRadioButton poufsouffle = new JRadioButton("Poufsouffle");

        // Création du groupe de bouton
        ButtonGroup g = new ButtonGroup();
        // Ajouts des boutons radio dans le groupe
        g.add(gryffondor);
        g.add(serdaigle);
        g.add(serpentard);
        g.add(poufsouffle);

        // Ajouts et placements des éléments dans l'écran
        /* OLD :
        fenetre.add(gryffondor,BorderLayout.NORTH);
        fenetre.add(serdaigle,BorderLayout.CENTER);
        fenetre.add(serpentard,BorderLayout.SOUTH); */
        
        FlowLayout container = new FlowLayout(FlowLayout.CENTER);
        fenetre.setLayout(container);
        fenetre.add(gryffondor);
        fenetre.add(serdaigle);
        fenetre.add(serpentard);
        fenetre.add(poufsouffle);




	    // Rend visible la fenetre
	    fenetre.setVisible(true);
    }
}