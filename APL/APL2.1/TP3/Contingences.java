import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Contingences {

    /**
    * @param args non-utilisé
    */
    public static void main(String[] args) {

    	// Fenetre
        JFrame fenetre = new JFrame("Saisie");
        // Configurations
    	fenetre.setSize(500, 300);
	    fenetre.setLocation(110, 110);
	    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	
    	// Texte dans le bas de la fenetre
    	JTextField fieldBottom = new JTextField(20);
        fenetre.add(fieldBottom, BorderLayout.SOUTH);
        
        JTextArea text = new JTextArea();
        // Wrap lines if needed
        text.setLineWrap(true);

        /* Au lieu d'afficher directement la zone de texte,
         * on affiche plutôt la classe qui la contient
         * et décide quelle partie du texte on affiche à l'écran
         * avec une bar de scroll si nécessaire.*/
        //fenetre.add(text, BorderLayout.CENTER);

        // Si besoin de scroll
        JScrollPane scrollableText = new JScrollPane(text);
        scrollableText.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        fenetre.add(scrollableText, BorderLayout.CENTER);
        // Couleurs
        text.setForeground(Color.GREEN);
        text.setBackground(Color.BLACK);

        fieldBottom.setForeground(Color.GREEN);
        fieldBottom.setBackground(Color.GRAY);
        
        // Rend la fenêtre visible
        fenetre.setVisible(true);
    }
}