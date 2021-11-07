import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.Objects;

/** feuille du motif composite */
public class Chef extends Person {
    private ArrayList<Person> sub;

    public boolean addSubalterne(Person p){
        return this.sub.add(p);
    }


    
    /** constructeur
     *
     * @param n fun factor
     *
     */ 
    public Chef(int n){
        super(n);
        this.sub = new ArrayList<Person>();
    }

    
    /** 
     * La meilleure fête avec moi, c'est la meilleure fête sans mes subalternes pour eux plus moi. 
     *
     * @return retourne la valeur de la meilleure fête en invitant seulement les gens dont cette personne est le ou la supérieure hiérarchique, mais pas elle.
     *
     */ 
    public int bestPartyWithoutMe(){
        int best = 0;
        for (Person p : sub) {
            best += p.bestParty();
        }
        return best;
    }

    /**
     *  La meilleure fête est soit sans moi (c'est l'union des meilleures fêtes de mes subalternes). 
     *  soit c'est la meilleure fête avec moi.
     *
     * @return la valeur de la meilleure fête en invitant seulement les gens dont cette personne est le ou la supérieure hiérarchique (peut-être avec elle).
     *
     */ 
    public int bestParty(){
        int withMe = this.getFunFactor();

        for (Person p : sub) {
            withMe += p.bestPartyWithoutMe();
        }

        int withoutMe = this.bestPartyWithoutMe();
        int max = Math.max(withMe,withoutMe);
        return max;
    }
}


