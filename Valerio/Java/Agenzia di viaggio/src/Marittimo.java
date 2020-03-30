public class Marittimo extends Cliente {
    private int coefficiente;

    Marittimo(String nome, int permanenza, int coefficiente) {
        super(nome, permanenza);
        this.coefficiente = coefficiente;
    }

    @Override
    public double soggiorno() {
        return coefficiente * getPermanenza();
    }
}