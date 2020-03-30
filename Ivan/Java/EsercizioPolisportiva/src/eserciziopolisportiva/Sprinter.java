package eserciziopolisportiva;

public class Sprinter extends Atleta{
    private int vittorie;

    public Sprinter(char nome, int età, int vittorie) {
        super(nome,età);
        this.vittorie = vittorie;
    }
    
    @Override
    public double premio() {
        return vittorie * 1000;
    }
    
}
