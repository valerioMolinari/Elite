public class Elemento  {
    public int n;
    public Elemento next;

    public Elemento(int n, Elemento next) {
        this.n = n;
        this.next = next;
    }

    public void setNext(Elemento next) { this.next = next; }
}