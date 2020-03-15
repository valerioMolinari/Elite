public class Felino extends Animale {
    private int coefficiente;

    Felino(String nome, double peso, int coefficiente ) {
        super(nome, peso);
        this.coefficiente = coefficiente;
    }

    @Override
    public double costo() {
        return coefficiente * getPeso();
    }
}