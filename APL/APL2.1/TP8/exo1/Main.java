import javax.swing.*;
import java.awt.*;

public class Main {
	public static void main(String[] args) {
		// Fenetre
        JFrame fenetre = new JFrame("Fond");
        
        // Panel qui contient les boutons
        JPanel panel = new JPanel();
        // Configurations de la fenêtre
        fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(300, 300));
        JButton bCyan = new JButton("Cyan");
        JButton bJaune = new JButton("Jaune");
        JButton bMagenta = new JButton("Magenta");

        Fond fond = new Fond(panel, bCyan, bJaune, bMagenta);

        bCyan.addActionListener(fond);
        bJaune.addActionListener(fond);
        bMagenta.addActionListener(fond);
        
        // Ajouts des boutons radio dans le groupe
        panel.add(bCyan);
        panel.add(bJaune);
        panel.add(bMagenta);

        panel.setLayout(new FlowLayout());

        fenetre.add(panel);

        fenetre.setVisible(true);

	}
}