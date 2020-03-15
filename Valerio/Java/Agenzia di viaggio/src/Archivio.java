import java.util.Random;

public class Archivio  {
    private Cliente[] V;
    private Random r = new Random();

    private class MatchClient {
        Boolean bool;
        Cliente client;
        MatchClient(Boolean bool, Cliente client) {
            this.bool = bool;
            this.client = client;
        }
    }

    private MatchClient vContains(String nome) {
        for (Cliente cliente : V)
            if (cliente != null && cliente.getNome().equals(nome))
                return new MatchClient(true, cliente);
        return new MatchClient(false, null);
    }

    private String newName() {
        String name;
        do {
            name = Cliente.nomi[r.nextInt(80)];
        } while (vContains(name).bool);
        return name;
    }

    Archivio(int m, int n) {
        V = new Cliente[m + n];
        for (int i = 0; i < m; i++)
            V[i] = new Marittimo(newName(), r.nextInt(13) + 1, (r.nextInt(3) + 1) * 30);
        for (int i = m; i < m + n; i++)
            V[i] = new Montanaro(newName(), r.nextInt(13) + 1, (r.nextInt(3) + 1) * 20);
    }

    public void visualizza() {
        System.out.printf("%s%15s%12s%10s\n\n", "Tipo Cliente", "Nome", "Permanenza", "Prezzo");
        for (Cliente c: V)
            System.out.printf("%12s%15s%7s%5s%8.2f €\n",
                    c.getClass().getCanonicalName(),
                    c.getNome(),
                    c.getPermanenza(), " ",
                    c.soggiorno()
            );
        System.out.println();
    }

    public double worth(String name) {
        MatchClient match = vContains(name);
        return match.bool ? match.client.soggiorno() : -1;
    }
}