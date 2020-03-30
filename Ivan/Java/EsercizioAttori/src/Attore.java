import java.util.Random;

public abstract class Attore {
    private String nome;
    private double età;
    private static String[] nomi = {"Ivan", "Giorgio", "Valerio", "Edoardo", "Berna", "Sasà", "Leo", "Gaia", "ZioGrannò"};

    public Attore(String nome, double età) {
        this.nome = nome;
        this.età = età;
    }

    public String getNome() { return nome; }

    public double getEtà() { return età; }
    
    public abstract double gradimento();
    
    /**
     *
     * @return
     */
    public static String nome() {
        Random r = new Random();
        return nomi[r.nextInt(nomi.length)];
        
    }
    
     public String className() { return getClass().getName(); }
    
}
