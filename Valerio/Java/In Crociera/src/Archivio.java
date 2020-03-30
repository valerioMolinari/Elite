import java.util.Random;

public class Archivio  {
    private Nave[] V;

    public Archivio(int n) {
        V = new Nave[n];
        Random r = new Random();

        for (int i = 0; i < n/2; i++)
            V[i] = new Crociera(Nave.newName(), r.nextInt(1000) + 5000);
        for (int i = n/2; i < n; i++)
            V[i] = new Trasporto(Nave.newName(), Math.random() * 130 + 70);
    }

    public Archivio(Nave[] V) {
        this.V = V;
    }

    public void visualizza() {
        System.out.printf("%12s%12s%14s\n\n", "Nave", "Nome", "Costo");
        for(Nave v : V)
            System.out.printf("%12s%12s%12.2f €\n", v.className(), v.getNome(), v.costoIscrizione());
        System.out.println();
    }

    public Archivio sostenibile(double limite) {
        Nave[] array;
        int count = 0;

        for (Nave v : V)
            if(v.costoIscrizione() < limite)
                count++;

        array = new Nave[count];
        count = 0;

        for (Nave v : V)
            if(v.costoIscrizione() < limite)
                array[count++] = v;

        return new Archivio(array);
    }

    public boolean sostenibileEasy(double limite) {
        for (Nave v : V)
            if (v.costoIscrizione() < limite)
                return true;
        return false;
    }
}