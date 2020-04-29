public class Professionista extends Musicista {
    private int anniConservatorio;

    public Professionista(String nome, int eta, int anniConservatorio) {
        super(nome, eta);
        this.anniConservatorio = anniConservatorio;
    }

    @Override
    public int rimborsoSpese() {
        return 10 * anniConservatorio + (getEta() > 35 ? 10 : 0);
    }
}