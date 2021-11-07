import javax.swing.*;
import java.awt.event.*;
public class SwitchListener implements MouseListener {
    private Fenetre window;
    // Constructeur
    public SwitchListener(Fenetre window) {
        this.window = window;
    }
     /**
     * Méthode sur clic souris, ne fait rien ici.
     */
    @Override
    public void mouseClicked(MouseEvent event) {

    }

    /**
     * Méthode sur appui souris, ne fait rien ici.
     */
    @Override
    public void mousePressed(MouseEvent event) {
    }

    /**
     * Méthode sur relachement de la souris, ne fait rien ici.
     */
    @Override
    public void mouseReleased(MouseEvent event) {
        if (event.getX() < this.window.getWidth() / 2) {
            this.window.remove(this.window.pic);
            this.window.pic = this.window.gal.switchPic(-1);
        } else if (event.getX() > this.window.getWidth() / 2) {
            this.window.remove(this.window.pic);
            this.window.pic =  this.window.gal.switchPic(1);
        }
        this.window.add(this.window.pic);
        this.window.revalidate();
    }

    /**
     * Méthode appelée lors du survol de la souris, ne fait rien ici.
     */
    @Override
    public void mouseEntered(MouseEvent event) {
    }

    /**
     * Méthode sur sortie de la souris, ne fait rien ici.
     */
    @Override
    public void mouseExited(MouseEvent event) {
    }
}