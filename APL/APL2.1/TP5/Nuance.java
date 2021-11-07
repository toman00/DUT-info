import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/
    
public class Nuance extends JPanel {
    private Dimension size = new Dimension(100, 100);
    private Dimension top = new Dimension(100,15);

    public Nuance(String hexaColorCode) {
        super();
        // Transforme la couleur de hexa (String) à integer
        Color temp = new Color(Integer.decode(hexaColorCode));
        String red = String.valueOf(temp.getRed());
        String green = String.valueOf(temp.getGreen());
        String blue = String.valueOf(temp.getBlue());
        this.setPreferredSize(size);
        this.setBackground(temp);
        JLabel label = new JLabel(red + ", " + green +  ", " + blue);
        label.setPreferredSize(top);
        label.setBackground(Color.BLACK);
        label.setForeground(Color.WHITE);
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setOpaque(true);
        // Ajout en haut de la fenêtre
        this.add(label, BorderLayout.NORTH);
    }

    /**
    * @param args utilisé
    */
    public static void main(String[] args) {
        // Variables 
        int length = args.length; // nb d'arguments
    	// Fenetre
        JFrame fenetre = new JFrame("Nuance");
        FlowLayout flowLayout = new FlowLayout(FlowLayout.CENTER);
        fenetre.setLayout(flowLayout);

        // Configurations de la fenêtre
        
	    fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // On créé autant de Nuance qu'il n'y a d'argument
        Nuance nuanceArray[] = new Nuance[length];
        // Tant qu'il y a des arguments on crée un Nuance associé
        for (int count = 0; count < length; ++count) {
            nuanceArray[count] = new Nuance(args[count]);
            // On ajoute enfin l'élément à la fenêtre
            fenetre.add(nuanceArray[count]);
        }
	    // Rend visible la fenetre
	    fenetre.setVisible(true);
        fenetre.pack();
    }
}