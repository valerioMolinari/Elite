abstract class Musicista  {
    private String nome;
    private int eta;
    public static String[] possibiliNomi = {
            "Evelyn","Pippo","Alice","Dina","Regina","Giulio","Salvatrice","Alfio",
            "Flavia","Dino","Anita","Salvo","Gabriella","Tancredi","Benito","Giulia",
            "Marcello","Calogera","Egidio","Loris","Amedeo","Paride","Tito",
            "Emanuele","Renato","Carmen","Gerlando","Miriam","Ennio","Emilia",
            "Mattia","Filippo","Uberto","Anna","Biagio","Piero","Angelo","Fabio",
            "Alberto","Beatrice","Paolo","Carmelo","Taddeo","Mirella","Saverio",
            "Sergio","Carlotta","Isabella","Calogero","Teogene","Emiliano","Antonio",
            "Osvaldo","Dante","Leandro","Corrado","Lino","Ulrico","Maria","Samuele",
            "Valerio","Marcella","Danilo","Lucio","Zeno","Ornella","Angela","Patrizio",
            "Michele","Marisa","Laura","Ruggero","Concetta","Nicola","Fedele","Vasco",
            "Agostino","Giancarlo","Pierluigi","Giuseppe"
    };

    Musicista(String nome, int eta) {
        this.nome = nome;
        this.eta = eta;
    }

    public void compleanno() {
        eta++;
    }

    public String getNome() {
        return nome;
    }

    public int getEta() {
        return eta;
    }

    public String professione() {
        String t = this.toString();
        return t.substring(0, t.indexOf("@"));
    }

    public abstract int rimborsoSpese();
}