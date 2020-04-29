import java.util.Random;

public class Archivio  {
    private Musicista[] V;

    public Archivio(int n, int m) {
        V = new Musicista[n + m];
        Random r = new Random();

        for (int i = 0; i < n; i++)
            V[i] = new Dilettante(Musicista.possibiliNomi[r.nextInt(40)], 18 + r.nextInt(12), r.nextBoolean());
        for (int i = n; i < n + m; i++)
            V[i] = new Professionista(Musicista.possibiliNomi[r.nextInt(40)], 25 + r.nextInt(41), 8 + r.nextInt(32));
    }

    public void mostraArchivio() {
        System.out.println("\t\tclasse\t\t\tNome\t\tEtà\t\tStipendio\n");
        for (Musicista m : V)
            System.out.printf("%14s\t\t%8s\t\t%3d\t\t%7d €\n",m.professione(), m.getNome(), m.getEta(), m.rimborsoSpese());
        System.out.println();
    }

    public int conta(int n) throws ArrayVuoto {
        if (V == null)
            throw new ArrayVuoto("Errore: L'array è vuoto");
        int count = 0;
        for (Musicista m : V)
            if (m.rimborsoSpese() > n)
                count++;
        return count;
    }
}