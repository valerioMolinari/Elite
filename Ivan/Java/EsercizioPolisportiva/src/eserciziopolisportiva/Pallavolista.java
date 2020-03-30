package eserciziopolisportiva;

public class Pallavolista extends Atleta {
    private int partiteGiocate;


    public Pallavolista(char nome, int età, int partiteGiocate) {
        super(nome, età);
        this.partiteGiocate = partiteGiocate;
    }

    @Override
    public double premio() {
        return partiteGiocate * 100;
    }

    
}
