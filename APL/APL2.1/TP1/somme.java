/**
* @version 1.0
* @author Tomy Da Rocha
*/
public class somme {
 
  /**
  * @param args utilisée
  */
  public static void main(String[] args) {
      /* Variables locales */
      int buffer = 0;
      int somme = 0, i;

      for (i = 0; i < args.length; ++i) {
        buffer = Integer.parseInt(args[i]);
        somme = somme + buffer;
      }
      System.out.println(somme);
  }
}