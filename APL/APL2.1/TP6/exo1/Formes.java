import javax.swing.*;
import java.awt.*;

/**
* @version 1.0
* @author Tomy Da Rocha
*/

public class Formes extends JComponent {
    private int tailleCarre = 50;
    private Image pic;
    
    public Formes() {
        super();
        this.pic = Toolkit.getDefaultToolkit().getImage("cercles.png");
    }    


    @Override
    public void paintComponent(Graphics pinceau) {

        Graphics secondPinceau = pinceau.create();
        if (this.isOpaque()) {
            secondPinceau.setColor(this.getBackground());
            secondPinceau.fillRect(0, 0, this.getWidth(), this.getHeight());
        }


        super.paintComponent(pinceau);
        // On crée un carré bleu de 50 pixels de côté
        secondPinceau.setColor(Color.BLUE);
        secondPinceau.drawRect((getWidth()/2) - this.tailleCarre/2, (getHeight()/2) - this.tailleCarre/2, this.tailleCarre, this.tailleCarre);

        // On écrit un texte, 24 de police gras, et en violet
        secondPinceau.setColor(Color.MAGENTA);
        secondPinceau.setFont(new Font("default", Font.BOLD, 24));
        secondPinceau.drawString(">o<", (getWidth()/2) - 20, getHeight()/2 - 30);


        // dessin d'un cercle vert de 25 de rayon 
        secondPinceau.setColor(Color.GREEN);
        secondPinceau.fillOval((getWidth()/2) - 25, (getHeight()/2) - 25, this.tailleCarre, this.tailleCarre);

        
        secondPinceau.drawImage(this.pic, 10, 10, this);
    }

    
    /**
    * @param args utilisée
    */
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
