/*
* Si realizzi una classe Java che abbia definito un metodo chiamato divisibile che
* accetta in ingresso due interi e restituisce true se il primo intero è divisibile
* per il secondo, salse in caso contrario
* */

import java.util.Scanner;

class MyClass {
    static boolean divisibile(int a, int b) {
        return a % b == 0;
    }

	public static void main(String[] args) {
        String play;
        Scanner s = new Scanner(System.in);
        do {
            System.out.print("Vuoi verificare la divisibilità di due numeri? (y/n): ");
            play = s.next();
            if (!play.equals("y")) {
                if (!play.equals("n"))
                    System.out.println("Scelta sbagliata");
                continue;
            }
            System.out.print("Inserisci due interi: ");
            int n1, n2;
            n1 = s.nextInt();
            n2 = s.nextInt();
            System.out.println(divisibile(n1, n2));
        } while (!play.equals("n"));
	}
}