public abstract class AnimaleDomestico extends Animale {
    protected String nome;

    public AnimaleDomestico(int eta, String nome) {
        super(eta);
        this.nome = nome;
    }

    @Override
    public void mostra() {
        System.out.println("Mi chiamo " + nome + " e ho " + eta + "anni");
    }
}