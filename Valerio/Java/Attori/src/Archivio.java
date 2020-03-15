import java.util.Random;

public class Archivio  {
    private Attore[] V;

    Archivio(int n) {
        V = new Attore[n];
        Random r = new Random();
        int c = n/3;
        for (int i = 0; i < c; i++)
            V[i] = new Comico(Attore.newName(), r.nextInt(35) + 25, r.nextInt(95) + 5);
        for (int i = c; i < n; i++) {
            V[i] = new Drammatico(Attore.newName(), r.nextInt(60) + 20, r.nextInt(25));
        }
    }

    public void visualizza() {
        System.out.printf("%12s%14s%6s%12s\n\n", "Attore", "Nome", "Età", "Gradimento");
        for (Attore a : V)
            System.out.printf("%12s%14s%6d%12.2f\n", a.className(), a.getNome(), a.getEta(), a.gradimento());
        System.out.println();
    }

    public int migliori(double n) {
        int count = 0;
        for (Attore a : V)
            if (a.gradimento() > n)
                count++;
        return count;
    }
}