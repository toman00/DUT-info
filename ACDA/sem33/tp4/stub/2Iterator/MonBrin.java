import java.util.Iterator;
import java.util.NoSuchElementException;

/** 
MonBrin code un brin d'ADN sous forme de liste simplement chaînée.
On n'utilise pas java.util (sauf pour les interfaces Iterator et Iterable pour faire joli) et on recode tout.

Cette version est correcte : la structuration et la navigation sont dans 2 classes séparées.
La classe MonBrin implémente Iterable au sens où elle peut générer à la demande un objet Iterator.

NB : Notez qu'on implémente Iterable<Base> plutôt que Iterable.
C'est un peu technique et c'est lié aux types génériques.
Il y a des détails ici 
https://stackoverflow.com/questions/20790770/why-cant-i-assign-a-raw-type-to-a-parameterized-type-java?rq=1

Dans ce fichier, je vous donne en cadeau un exemple de javadoc
*/

public class MonBrin implements Iterable<Base> {
    private MonBrin suivant;
    private Base bn;
    private MonBrin doigt;


    /**
      C'est le constructeur de base (pun intended) qui construit un brin à une base

      @param b : la base

      Ici je pourrais mettre un commentaire plus long sur le fonctionement détaillé de mon super constructeur.
      
    */
    public MonBrin(Base b){
        this.bn = b;
        this.suivant = null;
        this.doigt = this;
    }

    /**
       C'est le constructeur évolué qui construit un brin en ajoutant la base donnée en argumant devant le brin donné en argument.
       
       @param b : la base qui va aller devant
       @param b : le brin qui sera à la suite
    */
    public MonBrin(Base b, MonBrin l){
        this.bn = b;
        this.doigt = this;
        this.suivant = l;
    }

    public Base getBase(){
        return this.bn;
    }

    public MonBrin getSuiteBrin(){
        return this.suivant;
    }
    
    /** Pour naviguer? 
        On implémente l'interface iterator de java.util ici
        L'avantage c'est que c'est standard et tout le monde comprendra sans trop de mal comment la navigation fonctionne.
    **/
    @Override
    public Iterator<Base> iterator() {
        throw new UnsupportedOperationException("pas encore implanté");
    }
    

}


