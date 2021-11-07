import javax.swing.*;
import java.awt.*;

public class Formes extends JComponent {
    // Booléen pour savoir si la fenêtre est active (true) ou non
    private boolean activeWindow;
    // Coordonnées des points pour faire un losange
    protected int[] xpoint;
    protected int[] ypoint;

    // Constructeur
    public Formes(boolean activeWindow) {
        super();
        this.activeWindow = activeWindow;
        // Allocation mémoire pour les coordonnées du losange
        xpoint = new int[4];
        ypoint = new int[4];
    }

    @Override
    public void paintComponent(Graphics pinceau) {
        Graphics secondPinceau = pinceau.create();
        if (this.isOpaque()) {
            secondPinceau.setColor(this.getBackground());
            secondPinceau.fillRect(0, 0, this.getWidth(), this.getHeight());
        }

        super.paintComponent(pinceau);
        // On affiche un cercle magenta si la fenêtre est active
        if (activeWindow == true) {
            secondPinceau.setColor(Color.magenta);
            secondPinceau.fillOval(0, 0, this.getWidth(), this.getHeight());
        }
        // Sinon on affiche un sablier
        else {
            xpoint[1] = this.getWidth(); 
            xpoint[3] = this.getWidth();

            ypoint[2] = this.getHeight();
            ypoint[3] = this.getHeight();
            // Dessine un losange (polygone en 4pts) jaune
            secondPinceau.setColor(Color.yellow);
            secondPinceau.fillPolygon(new Polygon(xpoint,ypoint,xpoint.length));
        }
    }
}
