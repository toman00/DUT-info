import java.util.ArrayList;

/** feuille du motif composite */
public class Travailleur extends Person {
    private ArrayList<Person> sub;

    /** constructeur
     *
     * @param n fun factor
     *
     */ 
    public Travailleur(int n){
        super(n);
    }
    
    /** 
     *
     * @return fête sans le travailleur
     */ 
    public int bestPartyWithoutMe(){
        return 0;
    }
    
    /**
     * @return fête avec le travailleur
     */
    public int bestParty(){
        return this.getFunFactor();
    }
    
    
}


