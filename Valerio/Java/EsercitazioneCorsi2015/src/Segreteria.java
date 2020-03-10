import java.util.Random;

class Segreteria  {
    private Corso[] V;

    Segreteria(int n, int m) {
        V = new Corso[n + m];
        Random r = new Random();

        for (int i = 0; i < n; i++)
            V[i] = new Base(r.nextInt(200), r.nextInt(100), r.nextInt(75));
        for (int i = n; i < m + n; i++)
            V[i] = new Avanzato(r.nextInt(100), r.nextInt(80), r.nextBoolean());
    }

    void stampaArray() {
        System.out.println("   Corso\t\tPartecipanti\t\tDurata\t\tCosto Iscrizione\n");
        for (Corso c : V)
            System.out.printf("%8s\t\t%12d\t\t%6d\t\t%14d €\n", c.getType(), c.getPartecipanti(), c.getDurata(), c.costoIscrizione());
        System.out.println();
    }

    int corsiSostenibili(int n) {
        int count = 0;
        for (Corso c : V)
            if(c.costoIscrizione() < n)
                count++;
        return count;
    }
}