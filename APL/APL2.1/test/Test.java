public class Document {
    protected String titre;
    protected String isbn;

    // Pour un livre
    public Document(String titre, String isbn) {
        this.titre = titre;
        this.isbn = isbn;
    }

    @Override
    public String toString() {
        return this.titre + " " + this.isbn;
    }
}

public class Ouvrage extends Document {
    private String auteur;
    
    
    public Ouvrage(String titre, String auteur, String isbn) {
        super(titre, isbn);
        this.auteur = auteur;
    }
    
    @Override
    public String toString() {
        return super.toString() + "auteur : " +this.auteur;
    }
}

public class Periodique extends Document {
    private int numero;

    
    public Periodique (String titre, int numero, String isbn) {
        super(titre, isbn);
        this.numero = numero;
    }

    @Override
    public String toString() {
        return super.toString() + "numéro : " + this.numero;
    }
}