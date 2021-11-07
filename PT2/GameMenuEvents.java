import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.io.File;

/**
 * Classe <code>GameMenuEvents</code> définissant les différents évènements souris
 * sur les boutons du Menu de jeu.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class GameMenuEvents implements MouseListener {
    // La fenêtre principale
    private MainWindow mainWindow;

    /**
     * Constructeur des évènements du Menu de jeu.
     * @param mainWindow La fenêtre principale.
     */
    public GameMenuEvents(MainWindow mainWindow) {
        // Fenêtre princiaple
        this.mainWindow = mainWindow;
    }

    /**
     * Méthode du clic souris.
     *      <ul>
     *      Bouton "<i>Nouvelle partie</i>":
     *      <li>Calcul d'une grille aléatoire.</li>
     *      <li>Mise à jour de la grille.</li>
     *      <li>Mise à jour du score et du gain.</li>
     *      <li>Affichage de la nouvelle grille.</li>
     *      </ul>
     *
     *      <ul>
     *      Bouton "<i>Sauvegarder</i>":
     *      <p>Sauvegarde sous la forme "date <b>+</b> heure <b>+</b> .grid".</p>
     *      <li>Affiche un message de confirmation ou d'erreur.</li>
     *      </ul>
     *
     *      <ul>
     *      Bouton "<i>Charger</i>":
     *      <li>Choix d'un fichier à charger.</li>
     *      <li>Si erreur -> affiche un message.</li>
     *      <li>Mise à jour de la grille.</li>
     *      <li>Mise à jour du score et du gain.</li>
     *      <li>Affichage de la nouvelle grille.</li>
     *      </ul>
     *
     *      <ul>
     *      Bouton "<i>Mode clair/sombre</i>":
     *      <li>Mise à jour des panneaux selon le mode.</li>
     *      </ul>
     *
     *      <ul>
     *      Bouton "<i>Quitter</i>":
     *      <li>Fermeture du jeu.</li>
     *      </ul>
     * @param event L'évènement.
     */
    @Override
    public void mouseClicked(MouseEvent event) {
        // Bouton cliqué
        JButton buttonClicked = (JButton) event.getSource();

        // Boite de dialogue de choix de fichier
        JFileChooser fileChooser = new JFileChooser(Defines.SAVE_PATH);
        // Extensions de fichiers (.grid)
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "SameGame GRID file", Defines.GRID_FILE_EXT);
        // Ajoute un filtre d'extension
        fileChooser.setFileFilter(filter);

        // Retour de la boîte de dialogue de choix de fichier
        int returnVal;

        // Quel bouton ?
        switch (buttonClicked.getText().toLowerCase()) {
            // Créer une nouvelle partie
            case "nouvelle partie":
                // Demande la création d'une nouvelle partie
                this.mainWindow.newGame();
                break;

            // Créer un nouveau fichier de sauvegarde
            case "sauvegarder":
                // Calcul du nom de fichier
                // Date et heure (sauvegarde)
                SimpleDateFormat format = new SimpleDateFormat("dd-MM-yyyy-HH-mm-ss");
                Date date = new Date();

                // Sauvegarde au format : date + heure + extension
                String fileName = Defines.SAVE_PATH + format.format(date) + "." + Defines.GRID_FILE_EXT;

                // Demande de sauvegarde de la partie dans un fichier
                fileChooser.setDialogTitle("Sauver une partie");
                fileChooser.setSelectedFile(new File(fileName));

                // Affichage de la boite de dialogue
                returnVal = fileChooser.showSaveDialog(this.mainWindow);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    // Fichier à sauver
                    File selectedFile = fileChooser.getSelectedFile();

                    // Demande de sauvegarde de fichier
                    this.mainWindow.saveFileGrid(selectedFile.getAbsolutePath());
                }
                break;

            // Charge une partie : ouvre un explorateur de fichiers
            case "charger" :
                // Demande de chargement de la partie depuis un fichier
                fileChooser.setDialogTitle("Charger une partie");

                // Affichage de la boite de dialogue
                returnVal = fileChooser.showOpenDialog(this.mainWindow);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    // Fichier à charger
                    File selectedFile = fileChooser.getSelectedFile();

                    // Demande de chargement de fichier
                    this.mainWindow.loadFileGrid(selectedFile.getAbsolutePath());
                }
                break;

            // Mode clair ou sombre
            case "mode clair/sombre" :
                // Demande de changement de mode
                this.mainWindow.askChangeMode();
                break;

            // Bouton quitter
            case "quitter" :
                // On quitte la fenêtre principale
                this.mainWindow.dispose();
                break;

            // Cas par défaut
            default:
                break;
        }
    }

    /**
     * Méthode sur appui souris, ne fait rien ici.
     */
    @Override
    public void mousePressed(MouseEvent event) {
    }

    /**
     * Méthode sur relachement de la souris, ne fait rien ici.
     */
    @Override
    public void mouseReleased(MouseEvent event) {
    }

    /**
     * Méthode appelée lors du survol de la souris, ne fait rien ici.
     */
    @Override
    public void mouseEntered(MouseEvent event) {
    }

    /**
     * Méthode sur sortie de la souris, ne fait rien ici.
     */
    @Override
    public void mouseExited(MouseEvent event) {
    }
}