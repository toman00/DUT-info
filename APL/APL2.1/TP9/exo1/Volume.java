import javax.swing.*;
import java.awt.*;

public class Volume extends JComponent {
    private int volumeSize; // Taille d'un rond de volume
    private Color volumeOff;
    private Color volumeOn;
    private VolumeRefresh refresher;

    // Constructeur
    public Volume(VolumeRefresh refresher) {
        this.refresher = refresher;
        this.volumeSize = 40; // 50px de diamètre
        this.volumeOff = Color.darkGray; // Couleur quand valeur à 0
        this.volumeOn = Color.green; // Couleur quand volume à 1
    }

    @Override
    protected void paintComponent(Graphics pinceau) {
        super.paintComponent(pinceau);
        Graphics secondPinceau = pinceau.create();
        if (this.isOpaque()) {
            secondPinceau.setColor(this.getBackground());
            secondPinceau.fillRect(0, 0, this.getWidth(), this.getHeight());
        }


        if (refresher.getCount() > 0) {
            secondPinceau.setColor(volumeOn);
            refresher.setCount(-1);
        }
        else {
            secondPinceau.setColor(volumeOff);
        }
        secondPinceau.fillOval(0, 0, volumeSize, volumeSize);  
    }
}