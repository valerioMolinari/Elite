package eserciziopolisportiva;

public abstract class Atleta {
    private char nome;
    private int età;

    public Atleta(char nome, int età) {
        this.nome = nome;
        this.età = età;
    }

    public char getNome() {
        return nome;
    }

    public int getEtà() {
        return età;
    }
    
    abstract double premio();
}
