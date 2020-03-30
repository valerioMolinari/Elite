package eserciziopolisportiva;
import java.util.Random;

public class Archivio {
    Atleta[] V;
    
    public Archivio(int n) {
        Random r = new Random();
        V = new Atleta[n];
        for(int i = 0; i < n/2; i++)
            V[i] = new Pallavolista((char) (r.nextInt(26)+97), r.nextInt(19)+16, r.nextInt(35));
        for (int j = n/2; j < V.length; j++)
            V[j] = new Sprinter((char) (r.nextInt(26)+97), r.nextInt(19)+16, r.nextInt(35));
    }
    
    public double mediaPremio() {
        int count = 0;
        double mediaPremio = 0;
        for (int i = 0; i < V.length; i++) {
            mediaPremio += V[i].premio();
            count++;
        }    
        return mediaPremio / count;
    }
    
    public void visualizza() {
        for(Atleta x : V)
            System.out.println("Nome: "+x.getNome()+ " Età: "+ x.getEtà()+ " Premio: "+ x.premio());
    }
}
