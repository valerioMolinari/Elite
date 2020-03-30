package eserciziolista;

public class Elemento  {
    int n;
    Elemento next = null;

    Elemento(int n, Elemento next) {
        this.n = n;
        this.next = next;
    }
}