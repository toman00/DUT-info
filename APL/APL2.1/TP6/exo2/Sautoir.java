import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/

public class Sautoir extends JComponent {
    // Coordonnées des points pour faire un losange
    protected int[] xpoint;
    protected int[] ypoint;


    

    
    public Sautoir() {
        super();
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

        xpoint[1] = this.getWidth(); 
        xpoint[3] = this.getWidth();

        ypoint[2] = this.getHeight();
        ypoint[3] = this.getHeight();
        // Dessine un losange (polygone en 4pts) bleu
        secondPinceau.setColor(Color.BLUE);
        secondPinceau.fillPolygon(new Polygon(xpoint,ypoint,xpoint.length));
        

    }
    
}
