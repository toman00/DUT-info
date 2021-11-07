import javax.swing.*;
import java.awt.event.*;
import java.lang.Thread;
import java.awt.Rectangle;

public class CloseEvent implements WindowListener {
    private Fenetre fenetre;

    // Constructeur
    public CloseEvent(Fenetre fenetre) {
    this.fenetre = fenetre;
    }

    @Override
    public void windowClosing(WindowEvent e) {
        int confirm = JOptionPane.showOptionDialog(
             null, "Are You Sure to Close Application?", 
             "Exit Confirmation", JOptionPane.YES_NO_OPTION, 
             JOptionPane.QUESTION_MESSAGE, null, null, null);
        if (confirm == 0) {
                Rectangle r = this.fenetre.getBounds();
                int h = r.height;
                int w = r.width;
            for(int i = 0;i < 26; i++) {
                Fenetre f = new Fenetre();
                f.setVisible(true);
                if (f.getHeight() > h) {
                    f.setLocation(i*100,i*100);
                } else if (f.getWidth() > w) {
                    f.setLocation(i*100,i*100);
                } 
                else {
                f.setLocation(i*100,i*100);
                }
                try {
                    Thread.sleep(50);
                } catch (InterruptedException a) {
                    System.err.println("error, search");
                }

            }

        }
    }
    @Override
    public void windowClosed(WindowEvent e) {
    }
    @Override
    public void windowDeactivated(WindowEvent e) {
    }
    @Override
    public void windowDeiconified(WindowEvent e) {
    }
    @Override
    public void windowIconified(WindowEvent e) {
    }
    @Override
    public void windowOpened(WindowEvent e) {
    }
    @Override
    public void windowActivated(WindowEvent e) {
    }
}