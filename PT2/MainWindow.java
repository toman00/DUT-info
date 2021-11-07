import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

/**
 * Classe <code>MainWindow</code> gérant tout l'affichage du jeu.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class MainWindow extends JFrame {
    // Grille sur laquelle tous les calculs sont faits
    protected Grid grid;

    // Panneaux
    // Zone de jeu -> la grille
    protected GridPanel gridPanel;
    // Zone de menu -> les boutons
    protected GameMenuPanel gameMenuPanel;
    // Zone de score
    protected ScorePanel scorePanel;
    // Panel de fin de partie
    protected EndPanel endPanel;
    // Liste de panneaux
    private ArrayList<GamePanel> panelsArray;

    // Mode sombre (true) ou clair (false)
    private boolean darkMode;

    /**
     * Constructeur de la classe.
     */
    public MainWindow() {
        // Titre de la fenêtre
        super("SameGame");
        
        // Création de la grille
        this.grid = new Grid();

        // Chargement du fichier par défaut
        this.grid.loadFileGrid(Defines.SAVE_PATH + Defines.DEFAULT_GRID_FILE);

        // Calcule les groupes de blocs
        this.grid.calculateGroups();

        // Réglage position/taille
        this.setLocation(0,0);

        // Par défaut, on est en mode clair
        this.darkMode = false;

        // Calcul de la taille minimale de la fenêtre
        // On considère que toutes les images ont la même taille
        int imageWidth = 50;
        int imageHeight = 50;

        // Taille d'une image
        File imageFile = new File(Defines.BLOCK_RED_IMAGE);
        BufferedImage image;
        try {
            image = ImageIO.read(imageFile);
            imageWidth = image.getWidth();
            imageHeight = image.getHeight();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Largeur de la fenetre
        int winMinWidth = Defines.NB_COLS * (imageWidth + Defines.PANEL_GAP) + 50;

        // Hauteur de la fenetre
        int winMinHeight = Defines.NB_ROWS * (imageHeight + Defines.PANEL_GAP) + 100;


        // Blocage de la taille de la fenêtre
        this.setSize(winMinWidth,winMinHeight);
        this.setResizable(false);

        // Icone de la fenêtre
        ImageIcon icon = new ImageIcon("img/icon.png");
        this.setIconImage(icon.getImage());

        // Opération de fermeture
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Layout de la fenêtre
        BorderLayout borderLayout = new BorderLayout();
        this.setLayout(borderLayout);

        // Création des zones (Panels)
        this.scorePanel = new ScorePanel(this);
        this.gridPanel = new GridPanel(this);
        this.gameMenuPanel = new GameMenuPanel(this);
        this.endPanel = new EndPanel(this);

        // Ajout des panneaux au tableau de panneaux
        this.panelsArray = new ArrayList<GamePanel>();
        this.panelsArray.add(this.scorePanel);
        this.panelsArray.add(this.gridPanel);
        this.panelsArray.add(this.gameMenuPanel);
        this.panelsArray.add(this.endPanel);

        // Ajoute les zones
        this.add(this.gridPanel, BorderLayout.CENTER);
        this.add(this.gameMenuPanel, BorderLayout.SOUTH);
        this.add(this.scorePanel,BorderLayout.NORTH);

        // Dessine le panneau grille
        this.gridPanel.drawPanel();
    }

    /**
     * Créer une nouvelle partie avec une grille aléatoire.
     */
    public void newGame() {
        // Création d'une grille aléatoire
        this.grid.buildRandomGrid();

        // Rafraichissement du panel
        this.gridPanel.repaint();

        // Remet à zéro le score et le gain
        this.scorePanel.resetScore();

        // Enlève l'écran de fin
        this.remove(this.endPanel);

        // Affiche la grille à l'écran
        this.add(this.gridPanel);

        // Actualisation
        this.revalidate();
        this.repaint();
    }

    /**
     * Sauvegarde de la grille actuelle dans un fichier.
     * @param fileName Nom du fichier de sauvegarde.
     */
    public void saveFileGrid(String fileName) {
        // Sauvegarde de la grille
        // Nom de fichier
        if (this.grid.saveFileGrid(fileName)) {
            // Affiche un message de confirmation
            JOptionPane.showMessageDialog(
                    this,
                    "Partie sauvegardée !",
                    "Succès",  JOptionPane.PLAIN_MESSAGE);
        }
        else {
            // Erreur
            JOptionPane.showMessageDialog(
                    this,
                    "Impossible de sauvegarder !",
                    "Erreur",  JOptionPane.ERROR_MESSAGE);
        }

        // Sauvegarde du score
        // Nom de fichier : ajoute l'extension pour le score
        // TODO : Futurs développements
    }

    /**
     * Chargement d'une grille à partir d'un fichier.
     * @param fileName Nom du fichier à charger.
     */
    public void loadFileGrid(String fileName) {
        // Chargement de la grille
        if (this.grid.loadFileGrid(fileName)) {
            // Si chargement réussi : recalcule les groupes
            this.grid.calculateGroups();

            // Rafraichissement du panel
            this.gridPanel.repaint();

            // Remet à zéro le score et le gain
            this.scorePanel.resetScore();
        }
        else {
            // Si il y a une erreur
            JOptionPane.showMessageDialog(
                this,
                "Impossible de charger ce fichier !",
                "Erreur",
                JOptionPane.ERROR_MESSAGE);
        }

        // Redessine le Panel contenant la grille
        this.gridPanel.repaint();
    }

    /**
     * Demande de changement de mode : clair / sombre.
     */
    public void askChangeMode() {
        // Réglage du mode inverse
        this.darkMode = !this.darkMode;

        // Pour tous les panneaux
        for (int panelIdx=0; panelIdx < this.panelsArray.size(); panelIdx++) {
            this.panelsArray.get(panelIdx).setDarkMode(this.darkMode);
        }
    }

    /**
     * Vérifie si la partie est finie.
     * @return true si la partie est terminée, false sinon.
     */
    public boolean isOver() {
        // Initialisé à faux -> la partie n'est pas finie
        boolean over = false;

        // Demande si la partie est finie
        if (this.grid.isOver()) {
            // Enlève la grille de jeu
            this.remove(this.gridPanel);

            // Affiche l'écran de fin
            this.add(this.endPanel);

            // Fin de partie -> true;
            over = true;

            // Actualisation
            this.revalidate();
            this.repaint();
        }
        return over;
    }

    /**
     * Méthode de mise à jour du score selon le groupe sélectionné.
     * @param group Groupe de blocs sélectionné.
     */
    public void updateScore(ArrayList<Integer> group) {
        // Mise à jour du score
        this.scorePanel.setScore(group.size());

        // Si il y a un groupe, on supprime les blocs du groupe
        this.grid.deleteGroup(group);

        // Remet à zéro le fond de chacune des cases
        this.gridPanel.resetGridBackground();

        // Redessine le Panel contenant la grille
        this.gridPanel.repaint();

        // Teste à chaque coup du joueur s'il a fini la partie
        this.isOver();
    }

    /**
     * Méthode de mise à jour du panneau de grille lors du survol
     * de souris sur un groupe de blocs.
     * @param hoverBlock Bloc actuellement survolé par la souris.
     */
    public void updateHover(Block hoverBlock) {
        // Index pour le hover
        int hoverIdx;

        // Colonne et ligne (respectivement)
        int col, row;

        // Récupère le groupe du bloc survolé
        ArrayList<Integer> group = this.grid.getBlockGroup(
            hoverBlock.rowIdx, hoverBlock.colIdx);

        // Index de bloc survolé
        int hoverBlocIdx = this.grid.getIndex(
            hoverBlock.rowIdx, hoverBlock.colIdx);

        // Vérifie si le groupe n'est pas nul (signifie que le bloc a des voisins)
        // et si la case n'est pas vide
        if (group != null && !(this.grid.isEmpty(hoverBlocIdx))) {
            // Pour tous les élements du groupe
            for (int blockIdx=0; blockIdx < group.size(); blockIdx++) {
                // Index des cases à mettre en avant (hover)
                // On récupère l'index de bloc
                hoverIdx = group.get(blockIdx);

                // Convertion d'un index en coordonnées (colonnes/lignes)
                col = this.grid.getCol(hoverIdx);
                row = this.grid.getRow(hoverIdx);

                // On applique un fond de couleur afin de voir le groupe entier
                this.gridPanel.panelHolder[row][col].setBackground(Defines.HOVERCOLOR);
            }

            // Redessine le Panel contenant la grille
            this.gridPanel.repaint();
        }
    }

    /**
     * Méthode qui permet de mettre à jour le fond de la grille.
     */
    public void resetGridBackground() {
        // Mise à jour du fond
        this.gridPanel.resetGridBackground();
    }
}
