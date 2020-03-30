public class Lista  {
    Elemento testa = null;

    public Lista(int n, int limite) {
        for(int i = 0; i < n; i++)
            testa = new Elemento((int) (Math.random() * limite), testa);
    }

    public void visualizzaWhile() {
        Elemento temp = testa;
        while (temp != null) {
            System.out.print(temp.n + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public void visualizzaFor() {
        for (Elemento l = testa; l != null; l = l.next)
            System.out.print(l.n + " -> ");
        System.out.println("null");
    }
}