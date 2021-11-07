import javax.swing.*;
import java.awt.*;

public class Main {
	public static void main(String[] args) {
		// Fenetre
        JFrame fenetre = new JFrame("Sautoir");

        // Configurations de la fenêtre
        fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(300, 300));

        // On met le JPanel sous forme de grille 5x5
        GridLayout grid = new GridLayout(5,5);
        fenetre.setLayout(grid);
        
        for (int i = 0; i < 25; ++i) {
            fenetre.add(new Sautoir());
        }

        fenetre.setVisible(true);

	}
}