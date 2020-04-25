public class Mucca extends AnimaleDaCortile {
    public Mucca(int eta, double peso) {
        super(eta, peso);
    }

    @Override
    public void verso() {
        System.out.println("muu");
    }
}