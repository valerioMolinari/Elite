public class Crociera extends Nave {
    private int capienza;

    public Crociera(String nome, int capienza) {
        super(nome);
        this.capienza = capienza;
    }

    @Override
    public double costoIscrizione() {
        return capienza * 100.5;
    }
}