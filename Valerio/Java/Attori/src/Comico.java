public class Comico extends Attore {
    private int filmfatti;

    public Comico(String nome, int eta, int filmfatti) {
        super(nome, eta);
        this.filmfatti = filmfatti;
    }

    @Override
    public double gradimento() {
        return filmfatti * .75;
    }
}