import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Count extends JFrame {
    private WheelDetect mouseWheelListener;
    private JPanel panel;
    private VolumeRefresh volumeRefresh;

    // Constructeur
    public Count() {
        // Configuration fenêtre
        super("Volume");
        this.setLocation(0,0);
        this.setSize(600,200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        panel = new JPanel(new BorderLayout());
        panel.setLayout(new GridLayout(1,10));

        this.volumeRefresh = new VolumeRefresh(panel);
        
        this.mouseWheelListener = new WheelDetect(this.volumeRefresh);
        this.addMouseWheelListener(mouseWheelListener);

        panel.setBackground(Color.gray);
        this.add(this.panel);
    }

}
