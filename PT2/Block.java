import javax.swing.*;
import java.awt.*;

/**
 * Classe <code>Block</code> qui permet de représenter les 3 types de blocs différents
 * (Rouge "<b>r</b>", Vert "<b>v</b>", Bleu "<b>b</b>").
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class Block extends JComponent {
    // Attributs
    private Grid grid;
    protected int rowIdx, colIdx;

    /**
     * Constructeur du bloc selon la colonne et la ligne de la grille.<br>
     * @param grid La grille à gérer.
     * @param row L'index de la colonne.
     * @param col L'index de la ligne.
     */
    public Block(Grid grid, int row, int col) {
        // Grille
        this.grid = grid;
        // Index de ligne
        this.rowIdx = row;
        // Index de colonnes
        this.colIdx = col;
    }

    /**
     * Méthode qui détermine l'apparence du composant.
     * Selon le caractère récupéré dans la grille, on attribue la couleur correspondante,
     * en prenant en compte le caractère vide (espace).
     * @param pinceau Pinceau de dessin.
     */
    @Override
    protected void paintComponent(Graphics pinceau) {
        // Récupère le pinceau
        super.paintComponent(pinceau);

        // Création d'un second pinceau
        Graphics secondPinceau = pinceau.create();
        if (this.isOpaque()) {
            // On peint le fond de la taille de la fenêtre avec la couleur déjà présente
            secondPinceau.setColor(this.getBackground());
            secondPinceau.fillRect(0, 0, this.getWidth(), this.getHeight());
        }

        // Caractère correspondant à la couleur
        char carac = this.grid.getCarac(this.rowIdx, this.colIdx);

        /* Attribue le bloc correspondant depuis une couleur d'entrée
         * - bloc rouge si caractère 'R'
         * - bloc vert si caractère 'V'
         * - bloc bleu si caractère 'B'
         */
        // Chemin vers l'image à dessiner
        String imagePath = Defines.BLOCK_GREEN_IMAGE;
        switch (carac) {
            // Vert
            case Defines.BLOCK_GREEN_CHARAC:
                imagePath = Defines.BLOCK_GREEN_IMAGE;
                break;

            // Bleu
            case Defines.BLOCK_BLUE_CHARAC:
                imagePath = Defines.BLOCK_BLUE_IMAGE;
                break;

            // Rouge
            case Defines.BLOCK_RED_CHARAC:
                imagePath = Defines.BLOCK_RED_IMAGE;
                break;

            // Vide
            case Defines.BLOCK_EMPTY_CHARAC:
                imagePath = Defines.BLOCK_EMPTY_IMAGE;
                break;

            // Cas par défaut
            default:
                break;
        }

        // Affiche l'image
        Image image = Toolkit.getDefaultToolkit().getImage(imagePath);
        secondPinceau.drawImage(image, 0, 0, this);
    }
}
