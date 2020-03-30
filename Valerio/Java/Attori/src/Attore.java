import java.util.Random;

public abstract class Attore  {
    // Attributi
    private String nome;
    private int eta;
    private static String[] nomi = {"Ubaldo","Egidio","Alfio","Dina","Lorenzo","Patrizia","Letizia","Stefano","Danila","Iacopo","Emanuele","Barbara","Viliberto","Marcello","Marisa","Marzia","Iside","Roberta","Cinzia","Emanuela","Noè","Isidoro","Renzo","Claudio","Alessio","Susanna","Bartolomeo","Pierluigi","Nazario","Zaccheo","Cesare","Gemma","Simona","Cirillo","Duccio","Oliviero","Maria","Serena","Tancredi","Dionisio","Laura","Flavia","Piera","Marcella","Emilio","Nunzio","Bastiano","Irene","Nino","Zanobi","Sandro","Mara","Alessandra","katia","Regina","Corrado","Luisa","Valerio","Rino","Isaia","Alessia","Iole","Alessandro","Calogero","Giorgia","Danilo","Diego","Ennio","Gerlanda","Ulrico","Agnese","Giulia","Fausto","Dante","Vasco","Iside","Concetta","Daniela","Enzo","Taddeo"};

    // Metodi privati

    // Costruttore

    public Attore(String nome, int eta) {
        this.nome = nome;
        this.eta = eta;
    }
    // Metodi pubblici

    // Getters

    public String getNome() { return nome; }

    public int getEta() { return eta; }

    public String className() { return getClass().getName(); }

    public static String newName() {
        Random r = new Random();
        return nomi[r.nextInt(nomi.length)];
    }

    // Setters

    // Metodi astratti
    public abstract double gradimento();
}