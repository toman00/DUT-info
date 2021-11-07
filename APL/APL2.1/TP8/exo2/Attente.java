import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Attente extends WindowTest { 
    private JPanel panel;
    private JComponent windowActivated;
    private JComponent windowDeactivated;
    // Constructeur
    public Attente(JPanel panel) {
        this.panel = panel;
        windowActivated = new Formes(true);
        windowDeactivated = new Formes(false);
        panel.setBackground(Color.green);
    }
    @Override
    public void windowActivated(WindowEvent event) {
        panel.add(windowActivated);
    }
    @Override
    public void windowDeactivated(WindowEvent event) {
        panel.add(windowDeactivated);
    }
}
