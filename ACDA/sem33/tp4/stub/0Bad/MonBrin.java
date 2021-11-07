/** 
    MonBrin code un brin d'ADN sous forme de liste simplement chaînée.
    On n'utilise pas java.util et on recode tout.

    Cette version ne propose pas d'interface particulière pour naviguer et expose la structure interne de liste chaînée.

    ce fichier est un stub pour vous permettre d'aller plus vite
*/
public class MonBrin {
    private MonBrin suivant;
    private Base bn;

    //Le constructeur de base retourne un brin à une base;
    public MonBrin(Base b){
        this.bn = b;
        this.suivant = null;
    }

    // Le constructeur évolué ajoute une base dans un nouveau brin devant le brin suite.
    public MonBrin(Base devant, MonBrin suite){
        this.bn = devant;
        this.suivant = suite;
    }

    // retourne la base du brin
    public Base getBase(){
        return this.bn;
    }

    // retourne le brin suivant
    public MonBrin getSuiteBrin(){
        return this.suivant;
    }
    
       

}


