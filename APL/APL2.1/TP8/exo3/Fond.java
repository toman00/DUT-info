import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Fond implements ActionListener { 
    private JComponent cyan;
    private JComponent jaune;
    private JComponent magenta;
    private JPanel panel;

    // Constructeur

    public Fond(JPanel panel, JComponent cyan, JComponent jaune, 
        JComponent magenta) {
        this.panel = panel;
        this.cyan = cyan;
        this.jaune = jaune;
        this.magenta = magenta;
    }

    public void actionPerformed(ActionEvent clic) {
        Object source = clic.getSource();
        if (source == this.cyan) {
            panel.setBackground(Color.cyan);
            cyan.setBackground(Color.cyan);
            jaune.setBackground(Color.cyan);
            magenta.setBackground(Color.cyan);
        }
        else if (source == this.jaune) {
            panel.setBackground(Color.yellow);
            jaune.setBackground(Color.yellow);
            cyan.setBackground(Color.yellow);
            magenta.setBackground(Color.yellow);
        }
        else if (source == this.magenta) {
            panel.setBackground(Color.magenta);
            magenta.setBackground(Color.magenta);
            jaune.setBackground(Color.magenta);
            cyan.setBackground(Color.magenta);
        }
    }
	
}