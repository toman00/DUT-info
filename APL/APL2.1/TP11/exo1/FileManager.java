import javax.swing.JComponent;
import java.awt.Graphics;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.image.*;
 
public class FileManager extends JPanel{

    public void paint(Graphics g) {
      Image img = creerImage();
      g.drawImage(img, 0,0,this);
       }


    public Image creerImage(){
        BufferedImage image = new BufferedImage(1024,768,BufferedImage.TYPE_INT_RGB);
          try {
          FileInputStream fichier = new FileInputStream("image.bin");
          DataInputStream flux = new DataInputStream(fichier);
          try {
            for(int i = 0; (i<1024)  && (flux.available() >= 8); i++){
              for(int j = 0; (j<768) && (flux.available() >= 8) ; j++){
                  
                //Byte val1 = flux.readByte();
                int r = flux.read();
                //Byte val2 = flux.readByte();
                int g = flux.read();
                //Byte val3 = flux.readByte();
                int b = flux.read();


                Color couleur = new Color(r, g, b);
                int rgb = couleur.getRGB();
                //System.out.println(i + " "+ j + " "+ rgb);
                image.setRGB(i,j,rgb);
              }
            }
          } catch(IOException e) {
            System.err.println("Impossible de lire dans le fichier reels.bin !");
          }
          try {
            flux.close();
          } catch(IOException e) {
            System.err.println("Impossible de fermer le fichier reels.bin !");
          }
        } catch(FileNotFoundException e) {
          System.err.println("Impossible d'ouvrir le fichier reels.bin en lecture !");
        }
        return image;
    }

}