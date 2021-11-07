import javax.swing.*;
import java.awt.*;

public class Galerie {
    // Tableau d'images
    private int index; // position actuelle
    private int nbImage;
    // Constructeur
    public Galerie() {
        this.index = 0;
        this.nbImage = 3;
   }

    // Permet de faire les transitions entre les differentes photos disponibles dans la galerie
    public JLabel switchPic(int pic) {
        if (pic == 1) {
            this.index += 1;
        }
        else if (pic == -1) {
            this.index -= 1;
        }

        if (this.index < 0) {
            this.index = this.nbImage - 1;
        }
        else if (this.index > this.nbImage - 1) {
            this.index = 0;
        }
        return getPicture(this.index);
    }

    public JLabel getPicture(int index) {
        JLabel picture = null;
        switch(index) {
            case 0:
                picture = new JLabel(new ImageIcon("goat.gif"));
                break;
            case 1:
                picture = new JLabel(new ImageIcon("why_close.jpg"));
                break;
            case 2:
                picture = new JLabel(new ImageIcon("goat.gif"));
                break;
        }
        return picture;
    }

}