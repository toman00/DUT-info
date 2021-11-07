import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main {
    public static void main(String[] args) {
        // Fenetre
        JFrame fenetre = new JFrame("Attente");
        JPanel panel = new JPanel(new BorderLayout());
        // Configurations de la fenêtre
        fenetre.setLocation(110, 110);
        fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Taille minimale de la fenetre
        fenetre.setMinimumSize(new Dimension(300, 300));
        

        fenetre.addWindowListener(new Attente(panel));
        fenetre.add(panel);
        fenetre.setVisible(true);
    }
}
