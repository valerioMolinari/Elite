import java.util.Random;

public class Oasi  {
    // Attributi
    private Animale[] V;

    // Metodi privati

    // Costruttore

    public Oasi(int n) {
        V = new Animale[n];
        Random r = new Random();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                if (r.nextBoolean())
                    V[i] = new Gatto(Animale.newName(0), Math.random() * 2.6 + 2);
                else
                    V[i] = new Leopardo(Animale.newName(0), Math.random() * 11 + 21);
            else
                V[i] = new Pachiderma(Animale.newName(1), r.nextInt(3300) + 2700, 0.02);
        }
    }


    // Metodi pubblici
    public void visualizza() {
        System.out.printf("%12s%12s%14s%13s\n\n","animale", "nome", "peso", "costo");
        for (Animale a : V)
            System.out.printf("%12s%12s%11.2f kg%11.2f €\n", a.className(), a.getNome(), a.getPeso(), a.costo());
        System.out.println();
    }

    public String[] piuCostoso() {
        Animale max = V[0];
        for (Animale a : V)
            max = max.costo() > a.costo() ? max : a;
        return new String[] { max.getNome(), max.className() };
    }

    // Getters

    // Setters
}