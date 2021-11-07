import java.util.Iterator;
import java.util.NoSuchElementException;

/** 
MonBrinIterator 

gère la navigation dans un Brin d'ADN

*/
public class MonBrinIterator implements Iterator<Base> {
    
    
    //Le constructeur de base retourne un brin à une base;
    public MonBrinIterator(MonBrin iter){
        
    }
    
    /** Pour naviguer? 
        On implémente l'interface iterable de java.util ici
        L'avantage c'est que c'est standard et tout le monde comprendra sans trop de mal comment la navogation fonctionne.
    **/
    
    @Override
    public boolean hasNext(){
        throw new UnsupportedOperationException("pas encore implanté");
    }

    @Override
    public Base next() {
        if (hasNext()) {
            Base bis = this.doigt.bn;
            this.doigt = this.doigt.suivant;
            return bis;
        }
        else {
            throw new NoSuchElementException();
        }
    }
 
}


