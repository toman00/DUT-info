import javax.swing.*;
import java.awt.*;

public class Fenetre extends JFrame {
    // Constructeur
    public Fenetre() {
        this.setTitle("Boutons");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        BoutonPanel b = new BoutonPanel();
        this.add(b);
        this.pack();
        Dimension min = this.getSize();
        this.setMinimumSize(min);
    }
}