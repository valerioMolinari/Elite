public class Zoo {
    protected Animale[] V;

    public Zoo(int n) {
        V = new Animale[n];
        for (int i = 0; i < n; i++) {
            if (i % 4 == 0)
                V[i] = new Cane((int)(Math.random()*10), "Cane");
            else if (i % 4 == 1)
                V[i] = new Gatto((int)(Math.random()*10), "Gatto");
            else if (i % 4 == 2)
                V[i] = new Mucca((int)(Math.random()*10), (int)(Math.random()*200) + 600);
            else
                V[i] = new Gallina((int)(Math.random()*10), (int)(Math.random()*1.5) + 2);
        }
    }

    public void alloZoo() {
        for(Animale a : V)
            a.verso();
    }

    public void mostra() {
        for(Animale a : V)
            a.mostra();
    }
}