import java.util.ArrayList;
import java.util.List;

public class Lista  {
    private Elemento testa = null;

    public Lista(int n, int limite) {
        for (int i = 0; i < n; i++)
            testa = new Elemento((int) (Math.random() * limite), testa);
    }

    public Lista(Elemento testa) {
        this.testa = testa;
    }

    public Elemento getTesta() {
        return testa;
    }

    public int length() {
        int i = 0;
        for(Elemento e = testa; e != null; e = e.getNext(), i++);
        return i;
    }

    public void visualizza() {
        for(Elemento e = testa; e != null; e = e.getNext())
            System.out.printf("%2d -> ", e.getValore());
        System.out.println("null");
    }

    public int somma() {
        int count = 0;
        for (Elemento e = testa; e != null; e = e.getNext())
            count += e.getValore();
        return count;
    }

    public double media() {
        double count = 0;
        for (Elemento e = testa; e != null; e = e.getNext())
            count += e.getValore();
        return count / length();
    }

    public int max() {
        int thisMax = 0;
        for (Elemento e = testa; e != null; e = e.getNext())
            thisMax = Math.max(thisMax, e.getValore());
        return thisMax;
    }

    public int min() {
        int thisMin = testa.getValore();
        for (Elemento e = testa; e != null; e = e.getNext())
            thisMin = Math.min(thisMin, e.getValore());
        return thisMin;
    }

    public int moda() {
        int max = max();
        int[] array = new int[max + 1];

        for (Elemento e = testa; e != null; e = e.getNext())
            array[e.getValore()]++;

        int index = 0;
        for (int j = 0; j < max; j++)
            index = array[index] > array[j] ? index : j;

        return index;
    }

    public int find(int value) {
        int i = 0;
        for (Elemento e = testa; e != null; e = e.getNext(), i++)
            if (e.getValore() == value)
                return i;
        return -1;
    }

    public int check(int value, String type) {
        int count = 0;
        for (Elemento e = testa; e != null; e = e.getNext())
            if ((type.equals("sup") && e.getValore() > value) || (type.equals("inf") && e.getValore() < value))
                count++;
        return count;
    }

    public int parity(String type) {
        int count = 0;
        for (Elemento e = testa; e != null; e = e.getNext())
            if ((type.equals("pari") && e.getValore() % 2 == 0) || (type.equals("dispari") && e.getValore() % 2 == 1))
                count++;
        return count;
    }

    public Lista sort(String senso) {
        int length = length();
        Elemento[] array = new Elemento[length];

        int i = 0;
        for (Elemento e = testa; e != null; e = e.getNext(), i++)
            array[i] = new Elemento(e.getValore(), e.getNext());

        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length - j - 1; k++)
                if ((senso.equals("crescente") && array[k].getValore() > array[k + 1].getValore()) || (senso.equals("decrescente") && array[k].getValore() < array[k+1].getValore())) {
                    Elemento temp = array[k];
                    array[k] = array[k+1];
                    array[k+1] = temp;
                }
        }

        for (int j = 0; j < length; j++)
            array[j].setNext(j == i - 1 ? null : array[j + 1]);

        return new Lista(array[0]);
    }

    public Lista merge(Lista a, Lista b) {
        return merge(a, b, "set");
    }

    public Lista merge(Lista a, Lista b, String returnType) {
        Lista c = a.sort("crescente");
        Lista d = b.sort("crescente");




        return null;
    }

    public void visualizzaRick() {
        visualizzaRick(testa);
    }

    private void visualizzaRick(Elemento e) {
        if (e == null)
            System.out.println("null");
        else {
            System.out.printf("%2d -> ", e.getValore());
            visualizzaRick(e.getNext());
        }
    }

    public int sommaRick() {
        return sommaRick(testa);
    }

    private int sommaRick(Elemento e) {
        if (e == null)
            return 0;
        return e.getValore() + sommaRick(e.getNext());
    }

    public double mediaRick() {
        return mediaRick(testa, length());
    }

    private double mediaRick(Elemento e, int length) {
        if (e == null)
            return 0;
        return (double) e.getValore() / length + mediaRick(e.getNext(), length);
    }

    public int maxRick() {
        return maxRick(testa);
    }

    private int maxRick(Elemento e) {
        if (e.getNext() == null)
            return e.getValore();
        return Math.max(e.getValore(), maxRick(e.getNext()));
    }

    public int minRick() {
        return minRick(testa);
    }

    private int minRick(Elemento e) {
        if (e.getNext() == null)
            return e.getValore();
        return Math.min(e.getValore(), minRick(e.getNext()));
    }

    public int findRick(int value) {
        return findRick(testa, value, 0);
    }

    private int findRick(Elemento e, int value, int index) {
        if (e.getValore() == value)
            return index;
        if (e.getNext() == null)
            return -1;
        return findRick(e.getNext(), value, index + 1);
    }

    public int parityRick(String type) {
        if (type.equals("pari"))
            return length() - parityRick(testa);
        else if (type.equals("dispari"))
            return parityRick(testa);
        else
            return -1;
    }

    private int parityRick(Elemento e) {
        if (e.getNext() == null)
            return e.getValore() % 2;
        return e.getValore() % 2 + parityRick(e.getNext());
    }

    public int checkRick(int value, String type) {
        if (!type.equals("inf") && !type.equals("sup"))
            return -1;
        return checkRick(testa, value, type);
    }

    private int checkRick(Elemento e, int value, String type) {
        int sup = e.getValore() > value ? 1 : 0;
        int inf = e.getValore() < value ? 1 : 0;
        int result = type.equals("inf") ? inf : sup;
        if (e.getNext() == null)
            return result;
        return result + checkRick(e.getNext(), value, type);
    }
}