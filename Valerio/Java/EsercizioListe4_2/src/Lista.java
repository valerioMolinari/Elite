public class Lista  {
    protected Elemento testa = null;

    public Lista(int n, int limite) {
        for (int i = 0; i < n; i++)
            testa = new Elemento((int) (Math.random() * limite), testa);
    }

    public Lista(Elemento testa) {
        this.testa = testa;
    }

    public int length() {
        int i = 0;
        for(Elemento e = testa; e != null; e = e.next, i++);
        return i;
    }

    public void visualizza() {
        for(Elemento e = testa; e != null; e = e.next)
            System.out.printf("%2d -> ", e.n);
        System.out.println("null");
    }

    public int somma() {
        int count = 0;
        for (Elemento e = testa; e != null; e = e.next)
            count += e.n;
        return count;
    }

    public double media() {
        double count = 0;
        for (Elemento e = testa; e != null; e = e.next)
            count += e.n;
        return count / length();
    }

    public int max() {
        int thisMax = 0;
        for (Elemento e = testa; e != null; e = e.next)
            thisMax = Math.max(thisMax, e.n);
        return thisMax;
    }

    public int min() {
        int thisMin = testa.n;
        for (Elemento e = testa; e != null; e = e.next)
            thisMin = Math.min(thisMin, e.n);
        return thisMin;
    }

    public int moda() {
        int max = max();
        int[] array = new int[max + 1];

        for (Elemento e = testa; e != null; e = e.next)
            array[e.n]++;

        int index = 0;
        for (int j = 0; j < max; j++)
            index = array[index] > array[j] ? index : j;

        return index;
    }

    public int find(int value) {
        int i = 0;
        for (Elemento e = testa; e != null; e = e.next, i++)
            if (e.n == value)
                return i;
        return -1;
    }

    public int check(int value, String type) {
        int count = 0;
        for (Elemento e = testa; e != null; e = e.next)
            if ((type.equals("sup") && e.n > value) || (type.equals("inf") && e.n < value))
                count++;
        return count;
    }

    public int parity(String type) {
        int count = 0;
        for (Elemento e = testa; e != null; e = e.next)
            if ((type.equals("pari") && e.n % 2 == 0) || (type.equals("dispari") && e.n % 2 == 1))
                count++;
        return count;
    }

    public Lista sort() {
        return sort("crescente");
    }

    public Lista sort(String senso) {
        if (testa == null)
            return this;
        int length = length();
        Elemento[] array = new Elemento[length];

        int i = 0;
        for (Elemento e = testa; e != null; e = e.next, i++)
            array[i] = new Elemento(e.n, e.next);

        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length - j - 1; k++)
                if ((senso.equals("crescente") && array[k].n > array[k + 1].n) || (senso.equals("decrescente") && array[k].n < array[k+1].n)) {
                    Elemento temp = array[k];
                    array[k] = array[k+1];
                    array[k+1] = temp;
                }
        }

        for (int j = 0; j < length; j++)
            array[j].setNext(j == i - 1 ? null : array[j + 1]);

        return new Lista(array[0]);
    }

    private Elemento build(Elemento head) {
        return build(head, null);
    }

    private Elemento build(Elemento head, Elemento listToBuild) {
        for(Elemento e = head; e != null; e = e.next)
            listToBuild = new Elemento(e.n, listToBuild);
        return listToBuild;
    }

    private Lista toSet(Lista list) {
        if (list.testa == null)
            return list;
        for (Elemento e = list.testa; e.next != null; e = e.next) {
            while (e.next.n == e.n) {
                if (e.next.next != null)
                    e.setNext(e.next.next);
                else {
                    e.setNext(null);
                    break;
                }
            }
            if (e.next == null)
                break;
        }
        return list;
    }


    public Lista merge(Lista a, Lista b) {
        return merge(a, b, "set");
    }

    public Lista merge(Lista a, Lista b, String returnType) {
        Elemento merge = build(a.testa);
        merge = build(b.testa, merge);

        Lista m = new Lista(merge).sort();

        if (returnType.equals("set"))
            return toSet(m);
        else if (returnType.equals("full"))
            return m;
        return null;
    }

    public Lista cross(Lista a, Lista b) {
        return cross(a, b, "set");
    }

    public Lista cross(Lista a, Lista b, String returnType) {
        Elemento cross = null;
        for (Elemento e = a.sort().testa; e != null; e = e.next)
            for (Elemento f = b.sort().testa; f != null; f = f.next)
                if (e.n == f.n) {
                    while (f != null && e.n == f.n) {
                        cross = new Elemento(e.n, cross);
                        f = f.next;
                    }
                    break;
                }
        Lista c = new Lista(cross).sort();
        if (returnType.equals("set"))
            return toSet(c);
        else if (returnType.equals("full"))
            return c;
        return null;
    }

    public Lista notCommon(Lista a, Lista b) {
        Elemento notCommon = merge(a, b).testa;
        Elemento cross = cross(a, b).testa;
        if (cross != null) {
            boolean flag = false;
            for (Elemento e = notCommon; e.next != null; e = e.next) {
                for (Elemento c = cross; c != null; c = c.next)
                    if (e.next.n == c.n) {
                        if (e.next.next != null)
                            e.setNext(e.next.next);
                        else {
                            e.setNext(null);
                            flag = true;
                        }
                    }
                if (flag)
                    break;
            }
        }
        return new Lista(notCommon);
    }

    public void visualizzaRick() {
        visualizzaRick(testa);
    }

    private void visualizzaRick(Elemento e) {
        if (e == null)
            System.out.println("null");
        else {
            System.out.printf("%2d -> ", e.n);
            visualizzaRick(e.next);
        }
    }

    public int sommaRick() {
        return sommaRick(testa);
    }

    private int sommaRick(Elemento e) {
        if (e == null)
            return 0;
        return e.n + sommaRick(e.next);
    }

//    public int sommaRicorsiva() {
//        return sommaRicorsiva(testa);
//    }
//
//    private int sommaRicorsiva(Elemento e) {
//        if (e == null)
//            return 0;
//        return e.n + sommaRicorsiva(e.next);
//    }

    public double mediaRick() {
        return mediaRick(testa, length());
    }

    private double mediaRick(Elemento e, int length) {
        if (e == null)
            return 0;
        return (double) e.n / length + mediaRick(e.next, length);
    }

    public int maxRick() {
        return maxRick(testa);
    }

    private int maxRick(Elemento e) {
        if (e.next == null)
            return e.n;
        return Math.max(e.n, maxRick(e.next));
    }

    public int minRick() {
        return minRick(testa);
    }

    private int minRick(Elemento e) {
        if (e.next == null)
            return e.n;
        return Math.min(e.n, minRick(e.next));
    }

    public int findRick(int value) {
        return findRick(testa, value, 0);
    }

    private int findRick(Elemento e, int value, int index) {
        if (e.n == value)
            return index;
        if (e.next == null)
            return -1;
        return findRick(e.next, value, index + 1);
    }



    public int parityRick(String type) {
        if (type.equals("pari"))
            return length() - parityRick(testa);
        else if (type.equals("dispari"))
            return parityRick(testa);
        else
            return -1;
    }

//    public int pariRicorsiva() {
//        if (lunghezza > 0)
//            return lunghezza - paritaRicorsiva(testa);
//        else
//            return 0;
//    }
//
//    private int pariRicorsiva(Elemento e) {
//        if (e.next == null)
//            return e.n % 2;
//        return e.n % 2 + paritaRicorsiva(e.next);
//    }


    private int parityRick(Elemento e) {
        if (e.next == null)
            return e.n % 2;
        return e.n % 2 + parityRick(e.next);
    }

    public int checkRick(int value, String type) {
        if (!type.equals("inf") && !type.equals("sup"))
            return -1;
        return checkRick(testa, value, type);
    }

    private int checkRick(Elemento e, int value, String type) {
        int sup = e.n > value ? 1 : 0;
        int inf = e.n < value ? 1 : 0;
        int result = type.equals("inf") ? inf : sup;
        if (e.next == null)
            return result;
        return result + checkRick(e.next, value, type);
    }

    public int maggiori(int n) {
        return maggiori(testa, n);
    }

    private int maggiori(Elemento e, int n) {
        if (e == null)
            return 0;
        return e.n > n ? 1 + maggiori(e.next, n) : maggiori(e.next, n);
    }

    public boolean decrescente() {
        if (testa == null)
            return true;
        return decrescente(testa);
    }

    private boolean decrescente(Elemento e) {
        if (e.next == null)
            return e.n < e.next.n;
        return e.n < e.next.n && decrescente(e.next);
    }

    public Lista inverti() {
        Elemento lista = null;
        for (Elemento e = testa; e != null; e = e.next)
            lista = new Elemento(e.n, lista);
        return new Lista(lista);
    }

    public Lista copiaMaggiore1(int n) {
        Elemento lista = null;
        for (Elemento e = testa; e != null; e = e.next)
            if (e.n > n)
                lista = new Elemento(e.n, lista);
        return new Lista(lista).inverti();
    }

    public Lista copiaMaggiore2(int n) {
        Elemento copia = null;
        Elemento temp = null;
        for (Elemento e = testa; e != null; e = e.next) {
            if (e.n > n && copia == null) {
                copia = new Elemento(e.n, null);
                temp = copia;
            }
            else if (e.n > n) {
                temp.next = new Elemento(e.n, null);
                temp = temp.next;
            }
        }
        return new Lista(copia);
    }

    public Lista copiaMaggioreRicorsiva(int n) {
        Elemento lista = null;
        return new Lista(copiaMaggioreRicorsiva(testa, lista, n));
    }

    private Elemento copiaMaggioreRicorsiva(Elemento e, Elemento lista, int n) {
        if (e == null)
            return null;
        if (e.n > n) {
            lista = new Elemento(e.n, copiaMaggioreRicorsiva(e.next, lista, n));
            return lista;
        }
        return lista;
    }
}