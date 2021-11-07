import java.io.*;
import java.util.*;

/**
 * Classe <code>Grid</code> : contient les fonctions de calcul sur la grille de blocs.
 * Les blocs ne sont pas stockés sous formes d'objet. Ici, ils sont stokés sous forme
 * de caractère permettant de représenter une couleur. De plus, le tableau de blocs
 * représenté en 2D est stocké sous forme 1D.
 * @author Théo Chollet, Tomy Da Rocha
 * @version 1.0
 */
public class Grid {
    // Tableau de caractères en 1D
    protected char[] caracArray;

    // Tableau des groupes adjacents de blocs
    private ArrayList<ArrayList<Integer>> tabGroups;

    /**
     * Constructeur du moteur de la grille.
     * Création d'un tableau de caractères : la grille.
     */
    public Grid() {
        // Création du tableau de caractères
        this.caracArray = new char[Defines.NB_ROWS * Defines.NB_COLS];
        // Création du tableau de groupes
        this.tabGroups = new ArrayList<ArrayList<Integer>>();
    }

    /**
     * Méthode qui récupère l'index à l'intérieur du tableau de caractères.
     * @param row L'index de la ligne.
     * @param col L'index de la colonne.
     * @return L'indice correspondant aux coordonnées d'entrée du tableau 1D.
     */
    public int getIndex(int row, int col) {
        return row * Defines.NB_COLS + col;
    }

    /**
     * Méthode qui récupère le caractère de grille, à une position donnée.
     * @param row L'index de la ligne.
     * @param col L'index de la colonne.
     * @return Le caractère représentant la couleur du bloc.
     */
     public char getCarac(int row, int col) {
        return this.caracArray[getIndex(row, col)];
    }

    /**
     * Méthode qui charge la grille à partir d'un fichier.
     * @param gridFilePath Le chemin du fichier sous forme de chaine de caractères.
     * @exception IOException Impossible d'exploiter le fichier.
     * @return true si le fichier est chargé ou, false si le fichier n'est pas chargé.
     */
    public boolean loadFileGrid(String gridFilePath) {
        // Etat du chargement de fichier
        boolean fileLoaded = true;

        try {
            // Lecture du contenu de fichier grille
            FileReader in = new FileReader(gridFilePath);

            // Index de caractère
            int idxCarac = 0;
            // Caractère lu dans le fichier
            int carac;

            try {
                // On lit autant de caractères qu'on a besoin pour construire la grille
                while ((carac = in.read()) != -1 && idxCarac < Defines.NB_COLS * Defines.NB_ROWS) {
                    // Si le caractère est différent de '\r' et de '\n'
                    if ((carac != 10) && (carac != 13)) {
                        // Ajoute le caractère au tableau
                        this.caracArray[idxCarac] = (char) carac;

                        // Incrémente l'index de caractère
                        idxCarac++;
                    }
                }

                // Bon nombre de caractères ?
                if (idxCarac != Defines.NB_COLS * Defines.NB_ROWS) {
                    fileLoaded = false;
                }
            }
            catch (IOException e) {
                // Erreur de lecture du contenu de fichier
                System.err.println("Impossible de lire le contenu du fichier : " + gridFilePath);
                fileLoaded = false;
            }
            try {
                // Fermeture du fichier
                in.close();
            }
            catch (IOException e) {
                System.err.println("Impossible de fermer le fichier : " + gridFilePath);
                fileLoaded = false;
            }
        } catch (IOException e) {
            System.err.println("Impossible d'ouvrir le fichier : " + gridFilePath);
            fileLoaded = false;
        }

        // Retourne l'état du chargement de fichier
        return fileLoaded;
    }

    /**
     * Méthode qui sauve la grille dans un fichier.
     * @param gridFilePath Le chemin du fichier sous forme de chaine de caractères.
     * @exception IOException Impossible d'exploiter le fichier.
     * @return true si le fichier est sauvegardé ou, false si le fichier n'est pas sauvegardé.
     */
    public boolean saveFileGrid(String gridFilePath) {
        // Etat de sauvegarde de fichier
        boolean fileSaved = true;
        try {
            // Ouverture du fichier en écriture
            FileWriter out = new FileWriter(gridFilePath);
            try {
                // Ecriture du tableau de caractères
                for (int idxCarac=0; idxCarac < this.caracArray.length; idxCarac++) {
                    // Prochaine ligne : '\r\n' (code ASCII : 13, 10)
                    // Tous les "NB_COLS" (nombre de colonnes), mais pas le premier élément
                    if (((idxCarac % Defines.NB_COLS) == 0)  && (idxCarac != 0)) {
                        out.write(13);
                        out.write(10);
                    }

                    // Ecriture du caractère
                    out.write(this.caracArray[idxCarac]);
                }
                try {
                    // Fermeture du fichier
                    out.close();
                }
                catch (IOException e) {
                    System.err.println("Impossible de fermer le fichier : " + gridFilePath);
                    fileSaved = false;
                }
            }
            catch (IOException e) {
                System.err.println("Impossible d'écrire dans le fichier : " + gridFilePath);
                fileSaved = false;
            }
            
        } catch (IOException e) {
            System.err.println("Impossible d'ouvrir le contenu du fichier : " + gridFilePath);
            fileSaved = false;
        }

        // Retourne l'état de sauvegarde du fichier
        return fileSaved;
    }

    /**
     * Méthode qui génère une grille aléatoire.
     *     En parcourant la grille vide, on va aléatoirement choisir de créer pour chaque position :
     *     <ul>
     *     <li>Un bloc rouge.</li>
     *     <li>Un bloc vert.</li>
     *     <li>Un bloc bleu.</li>
     *     </ul>
     *     La méthode calcule à la fin les groupes de blocs voisins.
     */
    public void buildRandomGrid() {
        // Initialisation de la partie aléatoire
        Random rand = new Random();
        int randIdx;
        
        // Pour toutes les lignes / colonnes
        for (int idxCarac=0; idxCarac < (Defines.NB_ROWS * Defines.NB_COLS); idxCarac++) {
            // Calcul d'un index aléatoire entre 0 et 2 inclus
            randIdx = rand.nextInt(3);

            // On attribue les couleurs selon le chiffre tiré au hasard
            switch (randIdx) {
                // 0 -> Rouge
                case 0:
                    this.caracArray[idxCarac] = Defines.BLOCK_RED_CHARAC;
                    break;
                // 1 -> Vert
                case 1:
                    this.caracArray[idxCarac] = Defines.BLOCK_GREEN_CHARAC;
                    break;
                // 2 -> Bleu
                case 2:
                    this.caracArray[idxCarac] = Defines.BLOCK_BLUE_CHARAC;
                    break;

                // Cas par défaut
                default:
                    break;
            }
        }

        // Calcule des groupes de blocs
        this.calculateGroups();
    }

    /**
     * Méthode qui recherche les voisins.
     *     Pour une position (row, col) de bloc dans la grille, on calcule si un voisin se
     *     trouve autour de lui dans les positions suivantes : gauche, droite, haut, bas.
     *     Si on trouve un voisin à un bloc, alors on continue de chercher récurcivement
     *     en appelant la même méthode. A chaque voisin trouvé, la méthode l'ajoute dans
     *     le tableau dynamique passé en paramètre.
     * @param row Index de la ligne du bloc dont on cherche le voisin.
     * @param col Index de la colonne du bloc dont on cherche le voisin.
     * @param tabNeighs Tableau dynamique qui contient les blocs voisins.
     */
    public void recurciveNeighs(int row, int col, ArrayList<Integer> tabNeighs) {
        // Index du voisin
        int neighIdx;

        // Calcule de l'index du courant
        int currentIdx = this.getIndex(row, col);

        // Voisin de gauche
        if ((col - 1) >= 0) {
            // Index du voisin de gauche
            neighIdx = this.getIndex(row, col - 1);

            // Voisin de même nature ?
            if (this.caracArray[currentIdx] == this.caracArray[neighIdx]) {
                // Oui -> Ajoute au tableau (s'il n'y est pas déjà)
                if (!tabNeighs.contains(neighIdx)) {
                    tabNeighs.add(neighIdx);

                    // On continue de chercher
                    this.recurciveNeighs(row, col - 1, tabNeighs);
                }
            }
        }

        // Voisin de droite
        if ((col + 1) < Defines.NB_COLS) {
            // Index du voisin de droite
            neighIdx = this.getIndex(row, col + 1);

            // Voisin de même nature ?
            if (this.caracArray[currentIdx] == this.caracArray[neighIdx]) {
                // Oui -> Ajoute au tableau (s'il n'y est pas déjà)
                if (!tabNeighs.contains(neighIdx)) {
                    tabNeighs.add(neighIdx);

                    // On continue de chercher
                    this.recurciveNeighs(row, col + 1, tabNeighs);
                }
            }
        }

        // Voisin du haut
        if ((row - 1) >= 0) {
            // Index du voisin du haut
            neighIdx = this.getIndex(row - 1, col);

            // Voisin de même nature ?
            if (caracArray[currentIdx] == caracArray[neighIdx]) {
                // Oui -> Ajoute au tableau (s'il n'y est pas déjà)
                if (!tabNeighs.contains(neighIdx)) {
                    tabNeighs.add(neighIdx);

                    // On continue de chercher
                    this.recurciveNeighs(row - 1, col, tabNeighs);
                }
            }
        }

        // Voisin du bas
        if ((row + 1) < Defines.NB_ROWS) {
            // Index du voisin du bas
            neighIdx = this.getIndex(row + 1, col);

            // Voisin de même nature ?
            if (this.caracArray[currentIdx] == this.caracArray[neighIdx]) {
                // Oui -> Ajoute au tableau (s'il n'y est pas déjà)
                if (!tabNeighs.contains(neighIdx)) {
                    tabNeighs.add(neighIdx);

                    // On continue de chercher
                    this.recurciveNeighs(row + 1, col, tabNeighs);
                }
            }
        }
    }

    /**
     * Calcul de tous les groupes de blocs.
     */
    public void calculateGroups() {
        // On vide le tableau actuel
        this.tabGroups.clear();

        // Pour tous les éléments de la grille
        for (int rowIdx = 0; rowIdx < Defines.NB_ROWS; rowIdx++) {
            for (int colIdx = 0; colIdx < Defines.NB_COLS; colIdx++) {
                // Recherche des voisins
                ArrayList<Integer> tabNeighs = new ArrayList<Integer>();
                this.recurciveNeighs(rowIdx, colIdx, tabNeighs);

                // Tri du tableau d'index de voisins
                Collections.sort(tabNeighs);

                // Mise à jour du tableau de groupes
                // Ajoute au tableau de groupes, s'il n'y est pas déjà et s'il n'est pas vide
                if (!tabNeighs.isEmpty()) {
                    if (!this.tabGroups.contains(tabNeighs) &&
                    !(this.caracArray[this.getIndex(rowIdx, colIdx)] == Defines.BLOCK_EMPTY_CHARAC)) {
                        this.tabGroups.add(tabNeighs);
                    }
                }
            }
        }
    }

    /**
     * Recherche d'un groupe qui contient le bloc.
     * @param row Coordonnée de la ligne de bloc.
     * @param col Coordonnée de la ligne de bloc.
     * @return Retourne le tableau dynamique contenant les indices de blocs du groupe.
     */
    public ArrayList<Integer> getBlockGroup(int row, int col) {
        // Groupe à retourner
        ArrayList<Integer> group = null;
        boolean found = false;

        // Calcul de l'index de bloc
        int blockIdx = getIndex(row, col);

        // Recherche dans le tableau de groupes
        for (int groupIdx=0; groupIdx < this.tabGroups.size(); groupIdx++) {
            // Le groupe de blocs
            group = this.tabGroups.get(groupIdx);

            // Est-ce que le bloc est dans le groupe ?
            if (group.contains(blockIdx)) {
                found = true;
                break;
            }
        }

        // Retourne le groupe trouvé (ou null si pas trouvé)
        if (found) {
            return group;
        }
        return null;
    }

    /**
     * Fonction récurcive de recherche des voisins du bas afin de faire tomber les blocs.
     * @param row Coordonnée de la ligne du bloc à faire tomber.
     * @param col  Coordonnée de la colonne du bloc à faire tomber.
     */
    public void recurciveDrops(int row, int col) {
        // Index du voisin du bas
        int neighIdx;

        // Index actuel du bloc
        int currentIdx = getIndex(row, col);

        // Recherche du voisin du bas
        if ((row + 1) < Defines.NB_ROWS) {
            // Index du voisin du bas
            neighIdx = getIndex(row + 1, col);

            // Voisin du bas vide ?
            if (this.caracArray[neighIdx] == Defines.BLOCK_EMPTY_CHARAC) {
                // Oui -> Déplace le bloc courant à la place du voisin
                this.caracArray[neighIdx] = this.caracArray[currentIdx];
                this.caracArray[currentIdx] = Defines.BLOCK_EMPTY_CHARAC;

                // On continue de chercher
                this.recurciveDrops(row + 1, col);
            }
        }
    }

    /**
     * Vide une colonne.
     * @param colIdx Index de colonne à vider.
     */
    public void emptyCol(int colIdx) {
        // Index de caractère
        int currentCaracIdx;

        // Vide la colonne : remplit de caractères espace
        for (int rowIdx = 0; rowIdx < Defines.NB_ROWS; rowIdx++) {
            currentCaracIdx = getIndex(rowIdx, colIdx);
            this.caracArray[currentCaracIdx] = Defines.BLOCK_EMPTY_CHARAC;
        }
    }

    /**
     * Permet d'avoir la liste des colonnes vides.
     * @return Retourne le tableau dynamique contenant les colonnes vides.
     */
    public ArrayList<Integer> getEmptyCols() {
        // Pour toutes les colonnes :
        // on teste le caractère de bas de colonne
        // on sous-entend que la descente des blocs a été faite avant
        ArrayList<Integer> emptyCols = new ArrayList<Integer>();
        int currentCaracIdx;

        // A la recherche des colonnes vides
        for (int colIdx=0; colIdx < Defines.NB_COLS; colIdx++) {
            currentCaracIdx = getIndex(Defines.NB_ROWS - 1, colIdx);
            if (this.caracArray[currentCaracIdx] == Defines.BLOCK_EMPTY_CHARAC) {
                emptyCols.add(colIdx);
            }
        }

        // Retourne la liste des colonnes vides
        return emptyCols;
    }

    /**
     * Fonction qui décale les colonnes à gauche.
     * @param colIdx Indice de colonne.
     */
    public void shiftColsLeft(int colIdx) {
        // Index de caractère
        int currentCaracIdx;
        int nextCaracIdx;

        // Fait décaler toutes les colonnes suivantes à gauche
        for (int nextIdx = colIdx; nextIdx < (Defines.NB_COLS - 1); nextIdx++) {
            for (int rowIdx = 0; rowIdx < Defines.NB_ROWS; rowIdx++) {
                currentCaracIdx = getIndex(rowIdx, nextIdx);
                nextCaracIdx = getIndex(rowIdx, nextIdx + 1);
                this.caracArray[currentCaracIdx] = this.caracArray[nextCaracIdx];
            }
        }

        // Vide la dernière colonne
        this.emptyCol(Defines.NB_COLS - 1);
    }

    /**
     * Efface les blocs d'un groupe entier.
     * @param group Groupe de blocs à éliminer.
     */
    public void deleteGroup(ArrayList<Integer> group) {
        // Index de groupe à supprimer
        int delIdx;

        // Si le groupe est inexistant -> rien à faire
        if (group == null) {
            return;
        }

        //--------------------------------------------------
        // Change tous les caractères indéxés dans le groupe
        for (int caracIdx=0; caracIdx < group.size(); caracIdx++) {
            // Index à suppprimer
            delIdx = group.get(caracIdx);
            this.caracArray[delIdx] = Defines.BLOCK_EMPTY_CHARAC;
        }

        //----------------------------------
        // Déplacements des blocs : descente
        // Pour tous les éléments de la grille
        // On cherche le plus bas --> rowIdx en décrémentant
        for (int rowIdx=(Defines.NB_ROWS - 1) ; rowIdx >= 0; rowIdx--) {
            for (int colIdx=0; colIdx < Defines.NB_COLS; colIdx++) {
                // Recherche récurcive des blocs à faire tomber
                this.recurciveDrops(rowIdx, colIdx);
            }
        }

        //-------------------------------------------
        // Déplacements des blocs : décalage à gauche
        // Pour tous les éléments de la grille
        // A expliquer / détailler ..........

        // Liste des colonnes à décaler (celles qui sont vides)
        // Tableau dynamique contenant les cases d'une même colonne vide
        ArrayList<Integer> emptyCols = this.getEmptyCols();

        int nbColsEmpty = emptyCols.size();
        int countCols = 0;
        while (countCols < nbColsEmpty) {
            // Décalage à gauche
            this.shiftColsLeft(emptyCols.get(0));

            // Recharge la liste des colonnes vides
            emptyCols = this.getEmptyCols();

            // Compteur de décalages
            countCols++;
        }

        //-------------------------------
        // Recalcule les groupes de blocs
        this.calculateGroups();
    }

    /**
     * Permet d'avoir la coordonnée de la ligne liée à cet index.
     * @param idx Index de bloc à exploiter.
     * @return Retourne la coordonnée de la ligne liée à cet index.
     */
    public int getRow(int idx) {
        // Garde la partie entière de la division
        return Math.floorDiv(idx, Defines.NB_COLS);
    }

    /** 
     * Permet d'avoir la coordonnée de la colonne liée à un index de bloc.
     * @param idx Index de bloc à exploiter.
     * @return Retourne la colonne correspondant à cet index.
     */ 
    public int getCol(int idx) {
        return idx % Defines.NB_COLS;
    }

    /**
     * Vérifie si la case correspondant à cet index est vide.
     * @param idx Index de la case à vérifier.
     * @return true si la case est vide, false sinon.
     */
    public boolean isEmpty(int idx) {
        // Vérifie si la case est vide
        return this.caracArray[idx] == Defines.BLOCK_EMPTY_CHARAC;
    }

    /**
     * Vérifie si la partie est finie.
     * Dès que ce tableau est vide, la partie est finie car aucun coup ne peut être joué
     * @return Retourne false si la partie est finie, vrai si la partie est finie.

     */
    public boolean isOver() {
        // Combien de groupes restent-ils ?
        return this.tabGroups.size() == 0;
    }
}