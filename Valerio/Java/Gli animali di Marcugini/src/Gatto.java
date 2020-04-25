public class Gatto extends AnimaleDomestico {
    public Gatto(int eta, String nome) {
        super(eta, nome);
    }

    @Override
    public void verso() {
        System.out.println("miao");
    }
}