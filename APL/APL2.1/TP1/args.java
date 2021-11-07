/**
* @version 1.0
* @author Tomy Da Rocha
*/
public class args {
 
  /**
  * @param args utilisée
  */
  public static void main(String[] args) {
    /* Variables locales */
    int i;

    for (i = 0; i < args.length; ++i) {
        System.out.println("Bonjour "+args[i]+" !");
    }
  }
}