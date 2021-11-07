import java.awt.event.*;

/* 
 * But : Sous-classe pour n'utiliser que les méthodes utiles 
 * de l'interface WindowListener et de la classe JComponent
 */

public abstract class WindowTest implements WindowListener {
    public void windowActivated(WindowEvent event) {
    }
    public void windowDeactivated(WindowEvent event) {
    }
    public void windowClosed(WindowEvent event) {
    }
    public void windowClosing(WindowEvent event) {
    }
    public void windowDeiconified(WindowEvent event) {
    }
    public void windowIconified(WindowEvent event) {
    }
    public void windowOpened(WindowEvent event) {
    }
}
