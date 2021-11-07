import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class WheelDetect implements MouseWheelListener {
    protected int volume;
    protected VolumeRefresh count;

    // Constructeur
    public WheelDetect(VolumeRefresh volume) {
    	this.count = volume;
    }
    

    public void mouseWheelMoved(MouseWheelEvent evenement) {
        this.volume = evenement.getWheelRotation();
        /* Si la valeur est négatif(scrolle vers le haut, on doit incrémenter
         * donc positif/absolute) */
        if (this.volume < 0) {
            this.count.setVolume(Math.abs(this.volume));
        }
        // Réciproquement ..
        else {
            this.count.setVolume(this.volume * -1);
        }
        
    }
}
