package eserciziolista;

public class Lista  {
    Elemento testa = null;

    public Lista(int n, int limite) {
        for(int i = 0; i < n; i++)
            testa = new Elemento((int) (Math.random() * limite), testa);
    }
    
    public Lista(Elemento e) {
        this.testa = e;   
    }
    
    public int somma(Elemento e) {
        if(e == null)
            return 0;
        return e.n + somma(e.next);       
    }
    
    public void visualizza() {
        for(Elemento e = testa; e != null; e = e.next)
            System.out.print(e.n+" ");
    }
    
    public int maggioriN(int n, Elemento e) {
        if(e == null)
            return 0;
        if(e.n > n)
            return 1 + maggioriN(n, e.next);
        else
            return maggioriN(n, e.next);
    }
    
    public boolean ordinata(Elemento e) {
        if (e.next == null)
            return true;
        if (e.n > e.next.n)
            return false;
        return ordinata(e.next);
    }
    
    public Lista copia(int n) {
        Elemento copia = null;
        for(Elemento e = testa; e != null; e = e.next) {
            if(e.n > n)
                copia = new Elemento(e.n, copia);
        }
        return new Lista(copia);
    }
    
    public Lista copiaOrdinata(int n) {
        Elemento coda = null;
        Elemento copia = null;
        for(Elemento e = testa; e != null; e = e.next) {
            if(e.n > n) {
                if(copia == null) {
                    copia = new Elemento(e.n, null);
                    coda = copia;
                }    
                else {
                    copia.next = new Elemento(e.n, null);
                    copia = copia.next;
                }
            }
        }    
        return new Lista(coda);
    }
    public void ordina() {
        int x;
        Elemento e = testa;
        do {
            if(e.n > e.next.n) {
                x = e.n;
                e.n = e.next.n;
                e.next.n = x;
                e = testa;
            }
            else
                e = e.next;
        }while(e.next != null);
    }
}