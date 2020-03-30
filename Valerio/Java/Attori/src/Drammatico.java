public class Drammatico extends Attore {
    private int premi;

    public Drammatico(String nome, int eta, int premi) {
        super(nome, eta);
        this.premi = premi;
    }

    @Override
    public double gradimento() {
        return premi * 1.25;
    }
}