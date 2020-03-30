import java.util.Random;

public class Archivio {
    Attore[] V;
    
    public Archivio(int n) {
        Random r = new Random();
        V = new Attore[n];
        
        for (int i = 0; i < n/3; i++)
            V[i] = new Comico(r.nextInt(14)+1, Attore.nome(), (double) r.nextInt(52)+18);
        for (int j = n/3; j < V.length; j++)
            V[j] = new Drammatico((double) r.nextInt(9)+ 1, Attore.nome(), (double) r.nextInt(52)+18);
    }
    
    public int bravoAttore(int n) {
        int count = 0;
        for (int i = 0; i < V.length; i++)
            if (V[i].gradimento() > n)
                count++;
        System.out.println("Il numero di attori graditi è: "+count);
        return count;    
    }
    
    public void visualizza() {
        for (int i = 0; i < V.length; i++)
            System.out.println(V[i].getClass()+" Nome: "+V[i].getNome()+ " Età: "+V[i].getEtà()+ " Gradimento: "+V[i].gradimento());
    }
}
