import javax.swing.*;
 
public class Fenetre extends JFrame {
    protected Galerie gal;
    protected JLabel pic;
    // Constructeur
    public Fenetre() {
        super("Galerie");
        CloseEvent close = new CloseEvent(this);
        this.setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
        this.addWindowListener(close);
        this.gal = new Galerie();
        this.pic = this.gal.getPicture(0);
        this.addMouseListener(new SwitchListener(this));
        this.add(pic);
        this.pack();
    }
}