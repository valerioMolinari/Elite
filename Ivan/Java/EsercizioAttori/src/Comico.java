public class Comico extends Attore {
    int filmfatti;

    public Comico(int filmfatti, String nome, double età) {
        super(nome, età);
        this.filmfatti = filmfatti;
    }
    
    @Override
    public double gradimento () {
        return filmfatti * 0.75;
    }
    
}
