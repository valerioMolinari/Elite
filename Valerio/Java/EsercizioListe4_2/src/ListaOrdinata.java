import java.util.Random;

class ListaOrdinata extends Lista {
    public ListaOrdinata(Elemento testa) {
        super(testa);
    }

    public ListaOrdinata(int n, int maxInc) {
        super(null);
        Random r = new Random();
        Elemento ultimo = null;
        int inc = maxInc;
        for (int i = 0; i < n; i++) {
            if (testa == null) {
                testa = new Elemento(r.nextInt(maxInc), null);
                ultimo = testa;
            } else {
                inc += maxInc;
                int random = 0;
                while (random < ultimo.n)
                    random = r.nextInt(inc);
                ultimo.next = new Elemento(random, null);
                ultimo = ultimo.next;
            }
        }
    }

    public void insert(int n) {
        for (Elemento e = testa; e != null; e = e.next) {
            if (e.next != null && e.next.n > n) {
                e.next = new Elemento(n, e.next);
                break;
            } else if (e.next == null) {
                e.next = new Elemento(n, e.next);
                break;
            }
        }
    }

    public Elemento delete(int n) {
        Elemento remove = null;
        if (testa == null)
            return null;
        if (testa.n == n) {
            remove = testa;
            testa = testa.next;
            return remove;
        }
        Elemento prev = null;
        for (Elemento e = testa; e.next != null; e = e.next)
            if (e.n == n) {
                remove = e;
                prev.next = e.next;
                return remove;
            } else
                prev = e;
        return null;
    }
}