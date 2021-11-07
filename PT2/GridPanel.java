import javax.swing.*;
import java.awt.*;

/**
 * Classe <code>GridPanel</code> responsable de la gestion de la grille de jeu.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class GridPanel extends GamePanel {
    // Panneau qui contient la représentation de la grille
    protected JPanel[][] panelHolder;

    /**
     * Constructeur de la classe.
     * @param mainWindow Fenêtre principale
     */
    public GridPanel(MainWindow mainWindow) {
        // Appel de la classe mère
        super(mainWindow);

        // Réglage du layout : ici une grille
        this.setLayout(
            new GridLayout(Defines.NB_ROWS, Defines.NB_COLS, Defines.PANEL_GAP, Defines.PANEL_GAP));
    }

    /**
     * Dessine chacun des blocs de la grille de jeu
     */
    public void drawPanel() {
        // Le bloc de la grille
        Block block;
        // Le Panel contenant le bloc
        JPanel blockPanel;

        // Tableau de panneaux, une case (un panel) va contenir un bloc
        this.panelHolder = new JPanel[Defines.NB_ROWS][Defines.NB_COLS];
        for(int rowIdx = 0; rowIdx < Defines.NB_ROWS; rowIdx++) {
            for (int colIdx = 0; colIdx < Defines.NB_COLS; colIdx++) {
                // Création du Panel qui contiendra le bloc
                blockPanel = new JPanel(new BorderLayout());

                // Ajout du panel contenant le bloc au panel général
                this.panelHolder[rowIdx][colIdx] = blockPanel;
                this.panelHolder[rowIdx][colIdx].setLayout(new BorderLayout());
                this.panelHolder[rowIdx][colIdx].setForeground(Color.BLUE);

                // Création du bloc dans la position (rowIdx, colIdx)
                block = new Block(this.mainWindow.grid, rowIdx, colIdx);

                // Ajout de l'écoute des évènements
                block.addMouseListener(new BlockEvents(this.mainWindow));
                this.panelHolder[rowIdx][colIdx].add(block, BorderLayout.CENTER);
                this.add(this.panelHolder[rowIdx][colIdx]);
            }
        }

        // Vérifie si la partie est finie
        this.mainWindow.isOver();

        // Reinitialise le fond de toutes les cases de la grille
        this.resetGridBackground();
    }

    /**
     * Réinitialise le fond de chacune des cases.
     */
    public void resetGridBackground() {
        for (int row = 0; row < Defines.NB_ROWS; row++) {
            for (int col = 0; col < Defines.NB_COLS; col++) {
                this.panelHolder[row][col].setBackground(null);
            }
        }

        // Redessine le panneau
        this.repaint();
    }
}