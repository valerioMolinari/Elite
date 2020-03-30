public class Trasporto extends Nave {
    private double tonnellaggio;

    public Trasporto(String nome, double tonnellaggio) {
        super(nome);
        this.tonnellaggio = tonnellaggio;
    }

    @Override
    public double costoIscrizione() {
        return tonnellaggio * 150;
    }
}