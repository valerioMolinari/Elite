public class Pachiderma extends Animale {
    private double coefficiente;

    Pachiderma(String nome, double peso, double coefficiente ) {
        super(nome, peso);
        this.coefficiente = coefficiente;
    }

    @Override
    public double costo() {
        return coefficiente * getPeso();
    }
}