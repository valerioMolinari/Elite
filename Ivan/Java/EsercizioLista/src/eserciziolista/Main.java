package eserciziolista;

public class Main {
    public static void main(String[] args) {
        Lista l = new Lista(10, 10);
        Lista l2 = l.copia(3);
        //Lista l3 = l.copiaOrdinata(3);
        l.visualizza();
        System.out.println();
        //System.out.println("La somma è : "+l.somma(l.testa));
        //System.out.println("I numeri maggiori sono: "+l.maggioriN(4, l.testa));
        //System.out.println(l.ordinata(l.testa));
        l2.visualizza();
        System.out.println();
        //l3.visualizza();
        l.ordina();
        l.visualizza();
        System.out.println();
    }
    
}
