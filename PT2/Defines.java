import java.awt.Color;

/**
 * Classe <code>Defines</code> qui définit les différentes constantes de l'application.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class Defines {
    // Nombre de colonnes / lignes dans la grille
    public static final int NB_COLS = 15;
    public static final int NB_ROWS = 10;

    // Gap entre panels de la grille
    public static final int PANEL_GAP = 0;

    // Caractères de blocs
    public static final char BLOCK_RED_CHARAC = 'R';
    public static final char BLOCK_GREEN_CHARAC = 'V';
    public static final char BLOCK_BLUE_CHARAC = 'B';
    public static final char BLOCK_EMPTY_CHARAC = ' ';

    // Images de blocs
    public static final String BLOCK_RED_IMAGE = "img/rouge.png";
    public static final String BLOCK_GREEN_IMAGE = "img/vert.png";
    public static final String BLOCK_BLUE_IMAGE = "img/bleu.png";
    public static final String BLOCK_EMPTY_IMAGE = "img/empty.png";

    // Les boutons
    public static final String[] BUTTONS_NAME = {"Nouvelle partie", "Sauvegarder",
            "Charger", "Mode clair/sombre", "Quitter"};

    // Répertoire de sauvegarde
    public static final String SAVE_PATH = "save/";
    // Extensions de fichiers
    public static final String GRID_FILE_EXT = "grid";
    // Fichier par défaut à charger
    public static final String DEFAULT_GRID_FILE = "default.grid";

    //--------------------------------Couleurs--------------------------------//
    // Couleur pour le hover
    public static final Color HOVERCOLOR = new Color(20,74,233,200);
    
    // Couleur de fond en mode clair
    public static final Color LIGHT_BACKGROUND = new Color(255,255,255);
    // Couleur des textes en mode clair
    public static final Color LIGHT_FOREGROUND = new Color(0,0,0);
    // Couleur de fond des boutons en mode clair
    public static final Color LIGHT_BUTTON = new Color(200,200,200);
    // Couleur des textes en mode sombre
    public static final Color DARK_FOREGROUND = new Color(255,255,255);
    // Couleur de fond en mode sombre
    public static final Color DARK_BACKGROUND = new Color(23,23,23);
    // Couleur de fond des boutons en mode sombre
    public static final Color DARK_BUTTON = new Color(51,46,48);
}