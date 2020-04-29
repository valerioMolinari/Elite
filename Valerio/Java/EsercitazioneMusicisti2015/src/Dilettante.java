public class Dilettante extends Musicista {
    private boolean saLeggere;

    public Dilettante(String nome, int eta, boolean saLeggere) {
        super(nome, eta);
        this.saLeggere = saLeggere;
    }

    @Override
    public int rimborsoSpese() {
        return 2 * getEta() + (saLeggere ? 10 : 0);
    }
}