public class Cane extends AnimaleDomestico {
    public Cane(int eta, String nome) {
        super(eta, nome);
    }

    @Override
    public void verso() {
        System.out.println("bau");
    }
}