import java.util.Random;

public class Garage  {
    private Veicolo[] V;

    public Garage(int n, int m) {
        Random r = new Random();
        V = new Veicolo[n + m];
        for (int i = 0; i < n; i++)
            V[i] = new Camion(150 + r.nextInt(150), r.nextInt(100_000), r.nextBoolean());
        for (int i = n; i < m + n; i++)
            V[i] = new Autobus(205 + r.nextInt(195), r.nextInt(100_000),20 + r.nextInt(80));
    }

    public boolean moneyEnough(int n) {
        int e = 0;
        for (Veicolo v: V) {
            e += v.assicurazione();
            if (e > n)
                return false;
        }
        return true;
    }

    public void showGarage() {
        System.out.println("Resoconto garage\n");
        System.out.println("\t Veicolo\t\tPotenza\t\tKilometri\n");
        int i = 0;
        for (Veicolo v: V)
            System.out.printf("%2d%-2c %7s\t\t%4d kW\t\t%6d km\n", ++i, '.', v.getType(), v.kW, v.getKm());
        System.out.println();
    }
}