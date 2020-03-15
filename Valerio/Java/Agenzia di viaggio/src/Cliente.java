public abstract class Cliente  {
    private String nome;
    private int permanenza;

    static String[] nomi = {
            "Onofrio","Cirillo","Fabrizio","Loredana","Rocco","Pasquale","Baldo","Giulio","Denise",
            "Giuseppina","Luigi","Zabedeo","Maria","Adelaide","Cosimo","Serena","Casimiro","Nazzareno","Iole","Ivano",
            "Fabiola","Zeno","Livio","Ottavio","Carmen","Vincenzo","Piera","Ubaldo","Antonella","Egidio","Lea","Ketty",
            "Rino","Nunzio","Benito","Saverio","Greta","Giulia","Savino","Lorena","Carlotta","Clarissa","Virone",
            "Gerlanda","Luca","Valentina","Teresa","Carmelo","Anita","Teodoro","katia","Federica","Stefano","Salvatore",
            "Francesca","Dario","Lucio","Zetico","Tullio","Umberto","Marta","Igor","Riccardo","Agnese","Massimo",
            "Agostino","Isidoro","Domenico","Sabrina","Tancredi","Iside","Valerio","Giacomo","Martino","Roberta",
            "Giovannna","Teogene","Zaccheo","Francesco","Beatrice"
    };

    Cliente(String nome, int permanenza) {
        this.nome = nome;
        this.permanenza = permanenza;
    }

    public String getNome() { return nome; }

    public int getPermanenza() { return permanenza; }

    public abstract double soggiorno();
}