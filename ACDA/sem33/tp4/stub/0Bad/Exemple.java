// Fichier Exemple pour le premier exercice sur l'ADN

public class Exemple{
    public static void main(String[] args) {
        // codon GCT code l'analine https://en.wikipedia.org/wiki/DNA_codon_table
        // stop codon TAG, voir https://en.wikipedia.org/wiki/Stop_codon
        
        System.out.println("construction du brin GCTTAG");
        MonBrin l = new MonBrin(Base.G);
        l = new MonBrin(Base.A,l);
        l = new MonBrin(Base.T,l);
        l = new MonBrin(Base.T,l);
        l = new MonBrin(Base.C,l);
        l = new MonBrin(Base.G,l);

        System.out.println("l'affichage par défaut ne va pas vous plaire");
        System.out.println(l.toString());

        System.out.println("On peut afficher en avançant");
        System.out.println("Il faut s'en inspirer pour implémenter l'interface iterator de Java.util");
        while (l != null){
            System.out.println(l.getBase());
            l = l.getSuiteBrin();
        }
    }
}
