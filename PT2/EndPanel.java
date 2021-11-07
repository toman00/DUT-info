import javax.swing.*;
import java.awt.*;

/**
 * Classe <code>EndPanel</code>, panneau de l'écran de fin.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class EndPanel extends GamePanel {
    // Attributs
    private JLabel message;

    /**
     * Constructeur qui ajoute un texte à l'écran de fin.
     * @param mainWindow : Fenêtre principale.
     */
    public EndPanel(MainWindow mainWindow) {
        // Appel de la classe mère
        super(mainWindow);

        // Layout du panel
        this.setLayout(new BorderLayout());

        // Création du message de fin
        this.message = new JLabel("Fin de la partie");

        // Police du message
        this.message.setFont(new Font(Font.SERIF,Font.BOLD,50));

        // Ajout au panneau de fin
        this.add(this.message, BorderLayout.CENTER);
    }

    /**
     * Méthode qui passe le panneau en mode "<b>Sombre</b>" ou "<b>clair</b>".<br>
     * @param darkMode : true si sombre, false pour clair.
     */
    public void setDarkMode(boolean darkMode) {
        // Appel de la classe mère
        super.setDarkMode(darkMode);

        // Le message affiché
        if (darkMode) {
            this.message.setForeground(Defines.DARK_FOREGROUND);
        }
        else {
            this.message.setForeground(Color.BLACK);
        }
    }
}