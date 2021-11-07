import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.image.*;

public class Main {
  /**

  * @param args la liste des arguments de la ligne de commande (inutilisée ici)
  */
  public static void main(String[] args) {

    JFrame fenetre = new JFrame();
    fenetre.add(new FileManager());
    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    fenetre.setSize(1024,768);
    
 
    fenetre.setVisible(true);
  }
    
}