public class Montanaro extends Cliente {
    private double coefficiente;

    Montanaro(String nome, int permanenza, double coefficiente) {
        super(nome, permanenza);
        this.coefficiente = coefficiente;
    }

    @Override
    public double soggiorno() {
        return coefficiente * getPermanenza();
    }
}