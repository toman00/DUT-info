import javax.swing.*;

/**
 * Classe <code>ScorePanel</code> qui actualise le score et le gain.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class ScorePanel extends GamePanel {
    // Score actuel
    private int score;

    // Score recemment obtenu
    private int gain;

    // Texte affichant le score dans le panel
    private JLabel scoreDisplay;

    /**
     * Constructeur de la classe.
     * @param mainWindow Fenêtre principale.
     */
    public ScorePanel(MainWindow mainWindow) {
        // Appel de la classe mère
        super(mainWindow);

        // Score initialisé à  0
        this.score = 0;

        // Gain à 0
        this.gain = 0;

        // Affiche le score
        this.scoreDisplay = new JLabel("Score : " + score + " (+" + this.gain + ")");
        this.add(this.scoreDisplay);
    }

    /**
     * Modifie le score actuel.
     * @param blocksGone Nombre de blocs disparus.
     */
    public void setScore(int blocksGone) {
        // S'il y a plus d'un bloc disparu, on calcule le score
        if (blocksGone > 1) {
            // Formule de calcul de score = (n-2)² où (n <- bloc).
            this.gain = (blocksGone - 2) * (blocksGone - 2);
            this.score += this.gain;

            // Rafraichissement du texte
            this.scoreDisplay.setText("Score : " + score + " (+" + this.gain + ")");
        }
    }

    /**
     * Remet le score et le gain à zéro
     */
    public void resetScore() {
        this.score = 0;
        this.gain = 0;

        // Rafraichissement visuel des valeurs
        this.scoreDisplay.setText("Score : " + score + " (+" + this.gain + ")");
    }

    /**
     * Méthode qui passe le panneau en mode "<b>Sombre</b>" ou "<b>clair</b>".<br>
     * @param darkMode : true si sombre, false pour clair.
     */
    public void setDarkMode(boolean darkMode) {
        // Appel de la classe mère
        super.setDarkMode(darkMode);

        // La zone d'affichage du score
        if (darkMode) {
            this.scoreDisplay.setForeground(Defines.DARK_FOREGROUND);
        }
        else {
            this.scoreDisplay.setForeground(Defines.LIGHT_FOREGROUND);
        }
    }
}