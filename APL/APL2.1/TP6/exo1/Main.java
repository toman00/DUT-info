import javax.swing.*;
import java.awt.*;

public class Main {
	public static void main(String[] args) {
		// Fenetre
        JFrame fenetre = new JFrame("Formes");

        // Configurations de la fenêtre
        fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(300, 300));
        fenetre.add(new Formes());
        fenetre.setVisible(true);

	}
}