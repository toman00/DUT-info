import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

/**
 * Classe <code>BlockEvents</code> qui permet de gérer les différents évènements souris sur les blocs.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class BlockEvents implements MouseListener {
    // La fenêtre principale
    protected MainWindow mainWindow;

    /**
     * Constructeur de la classe.
     * @param mainWindow La fenêtre principale.
     */
    public BlockEvents(MainWindow mainWindow) {
        // La fenêtre principale
        this.mainWindow = mainWindow;
    }

    /**
     * Méthode du clic souris.
     * <ul>
     *      Lorsqu'un clic est fait sur un groupe non-vide :
     *      <li>Suppression des blocs à l'intérieur du groupe.</li>
     *      <li>Mise à jour du panneau d'affichage de la grille.</li>
     *      <li>Teste si la partie est finie.</li>
     * </ul>
     * @param event L'évènement.
     */
    @Override
    public void mouseClicked(MouseEvent event) {
        // Index de bloc
        int blockIdx;

        // Récupération du bloc concerné (la source de l'évènement)
        Block clickedBlock = (Block) event.getSource();

        // Recherche du groupe de blocs concerné
        ArrayList<Integer> group = this.mainWindow.grid.getBlockGroup(
            clickedBlock.rowIdx, clickedBlock.colIdx);

        // Récupération de l'index de bloc
        blockIdx = this.mainWindow.grid.getIndex(
            clickedBlock.rowIdx, clickedBlock.colIdx);

        // Vérifie si le groupe n'est pas nul (signifie qu'il reste que des blocs sans voisin)
        // et si la case n'est pas vide
        if (group != null && !(this.mainWindow.grid.isEmpty(blockIdx))) {
            // Mise à jour du score
            this.mainWindow.updateScore(group);
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
     * Méthode appelée lors du survol de la souris.
     *      Lorsque la souris survole un groupe non-vide, on affiche un effet de hover (survol).
     * @param event L'évènement.
     */
    @Override
    public void mouseEntered(MouseEvent event) {
        // Récupération du bloc concerné (la source de l'évènement)
        Block hoverBlock = (Block) event.getSource();

        // Mise à jour du survol
        this.mainWindow.updateHover(hoverBlock);
    }

    /**
     * Méthode sur sortie de la souris.
     */
    @Override
    public void mouseExited(MouseEvent event) {
        // Ré-initialise le fond de la grille
        this.mainWindow.resetGridBackground();
    }
}