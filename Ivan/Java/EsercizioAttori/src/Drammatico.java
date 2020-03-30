public class Drammatico extends Attore {
    double premi;

    public Drammatico(double premi, String nome, double età) {
        super(nome, età);
        this.premi = premi;
    }
    
    @Override
    public double gradimento () {
        return premi * 1.25;
    }
    
}
