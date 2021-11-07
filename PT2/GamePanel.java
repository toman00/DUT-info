// Importation des bibliothèques
import javax.swing.*;
import java.awt.*;

/**
 * Classe <code>GamePanel</code> panneau de base pour tous les panneaux du jeu.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class GamePanel extends JPanel {
    // La fenêtre principale
    protected MainWindow mainWindow;

    /**
     * Constructeur du panneau générique du jeu.
     * @param mainWindow : La fenêtre principale.
     */
    public GamePanel(MainWindow mainWindow) {
        // La fenêtre principale
        this.mainWindow = mainWindow;

        // Réglage d'un Layout par défaut
        this.setLayout(new FlowLayout());
    }

    /**
     * Méthode qui passe le panneau en mode "<b>Sombre</b>" ou "<b>clair</b>".
     * @param darkMode : true si sombre, false pour clair.
     */
    public void setDarkMode(boolean darkMode) {
        if (darkMode) {
            this.setBackground(Defines.DARK_BACKGROUND);
        }
        else {
            this.setBackground(Defines.LIGHT_BACKGROUND);
        }
    }
}
