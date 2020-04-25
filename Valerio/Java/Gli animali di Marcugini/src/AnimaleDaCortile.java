public abstract class AnimaleDaCortile extends Animale {
    protected double peso;

    public AnimaleDaCortile(int eta, double peso) {
        super(eta);
        this.peso = peso;
    }

    @Override
    public void mostra() {
        System.out.println("Ho " + eta + " anni e peso " + peso + "kg");
    }
}