import java.util.Scanner;

public class Tester  {
	public static void main(String[] args) {
		Scanner tastiera = new Scanner(System.in);
		Lista l = new Lista(20, 20);
		System.out.println("Visualizzazione:");
		l.visualizza();
		System.out.println("\nVisualizza ricorsiva:");
		l.visualizzaRick();
		System.out.println("\nSomma: " + l.somma());
		System.out.println("Somma ricorsiva: " + l.sommaRick());
		System.out.printf("\nMedia: %.2f\n", l.media());
		System.out.printf("Media ricorsiva: %.2f\n", l.mediaRick());
		System.out.println("\nMassimo: " + l.max());
		System.out.println("Massimo ricorsivo: " + l.maxRick());
		System.out.println("\nMinimo: " + l.min());
		System.out.println("Minimo ricorsivo: " + l.minRick());
		System.out.print("\nInserisci un elemento di cui vuoi conoscere l'indice: ");
		int f = 5; //tastiera.nextInt();
		System.out.println("\nTrova: " + l.find(f));
		System.out.println("Trova ricorsivamente: " + l.findRick(f));
		System.out.println("\nNumeri pari: " + l.parity("pari"));
		System.out.println("Numeri pari ricorsivi: " + l.parityRick("pari"));
		f = 9;
		System.out.printf("\nNumeri maggiori di %d: %d\n", f, l.check(f, "sup"));
		System.out.printf("Numeri maggiori di %d ricorsivamente: %d\n", f, l.checkRick(f, "sup"));

		Lista a = new Lista(20, 10);
		Lista b = new Lista(20, 10);
		l.merge(a, b);
	}
}