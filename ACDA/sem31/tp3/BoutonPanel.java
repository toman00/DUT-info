import javax.swing.*;
import java.awt.*;

public class BoutonPanel extends JPanel {

    // Constructeur
    public BoutonPanel() {
        super(new GridBagLayout());
        // Création de 5 boutons
        JButton a = new JButton("1");
        JButton b = new JButton("2");
        JButton c = new JButton("3");
        JButton d = new JButton("4");
        JButton e = new JButton("5");
        // 1
        GridBagConstraints gbca = new GridBagConstraints();
        gbca.gridx = 0;
        gbca.gridy = 0;
        gbca.gridwidth = 2;
        gbca.gridheight = 1;
        gbca.weightx = 1.0;
        gbca.weighty = 1.0;
        gbca.fill = GridBagConstraints.BOTH;
        gbca.anchor = GridBagConstraints.FIRST_LINE_START;
        this.add(a,gbca);

        // 2
        GridBagConstraints gbcb = new GridBagConstraints();
        gbcb.gridx = 2;
        gbcb.gridy = 0;
        gbcb.gridwidth = 1;
        gbcb.gridheight = 2;
        gbcb.weightx = 1.0;
        gbcb.weighty = 1.0;
        gbcb.fill = GridBagConstraints.BOTH;
        gbcb.anchor = GridBagConstraints.PAGE_START;
        this.add(b,gbcb);

        // 3
        GridBagConstraints gbcc = new GridBagConstraints();
        gbcc.gridx = 1;
        gbcc.gridy = 2;
        gbcc.gridwidth = 2;
        gbcc.gridheight = 1;
        gbcc.weightx = 1.0;
        gbcc.weighty = 1.0;
        gbcc.fill = GridBagConstraints.BOTH;
        gbcc.anchor = GridBagConstraints.PAGE_END;
        this.add(c,gbcc);

        // 4
        GridBagConstraints gbcd = new GridBagConstraints();
        gbcd.gridx = 0;
        gbcd.gridy = 1;
        gbcd.gridwidth = 1;
        gbcd.gridheight = 2;
        gbcd.weightx = 1.0;
        gbcd.weighty = 1.0;
        gbcd.fill = GridBagConstraints.BOTH;
        gbcd.anchor = GridBagConstraints.LINE_START;
        this.add(d,gbcd);


        // 5
        GridBagConstraints gbce = new GridBagConstraints();
        gbce.gridx = 1;
        gbce.gridy = 1;
        gbce.gridwidth = 1;
        gbce.fill = GridBagConstraints.NONE;
        gbce.anchor = GridBagConstraints.CENTER;
        this.add(e,gbce);
    }
}