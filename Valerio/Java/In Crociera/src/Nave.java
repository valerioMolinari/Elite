import java.util.Random;

public abstract class Nave {
    private String nome;
    private static String[] nomi = {"Denise","Adelaide","Valeria","Clarissa","Laura","Betty","Daniela","Anna","Rosella","Stefania","Erica","Maria","Piera","Iside","Carmen","Marta","Luciana","Pamela","Lucia","Giuseppina","Marzia","Luisa","Floriana","Iole","Barbara","Angela","Regina","Anita","Ketty","Debora","Caterina","Giulia","Paola","Ornella","Greta","Giorgia","Patrizia","Beatrice","Ada","Domenica","Mara","Sara","Corinna","Claudia","Elisa","Ida","Danila","Susanna","Iolanda","Lea"};

    public Nave(String nome) {
        this.nome = nome;
    }

    public String getNome() { return nome; }

    public static String newName() {
        Random r = new Random();
        return nomi[r.nextInt(nomi.length)];
    }

    public String className() {
        return getClass().getName();
    }

    public abstract double costoIscrizione();
}