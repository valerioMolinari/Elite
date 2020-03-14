public class Elemento  {
    private int valore;
    private Elemento next;

    public Elemento(int valore, Elemento next) {
        this.valore = valore;
        this.next = next;
    }

    public int getValore() { return valore; }

    public Elemento getNext() { return next; }

    public void setNext(Elemento next) { this.next = next; }
}