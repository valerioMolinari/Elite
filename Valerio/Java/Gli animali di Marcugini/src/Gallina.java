public class Gallina extends AnimaleDaCortile {
    public Gallina(int eta, double peso) {
        super(eta, peso);
    }

    @Override
    public void verso() {
        System.out.println("chicchirichi");
    }
}