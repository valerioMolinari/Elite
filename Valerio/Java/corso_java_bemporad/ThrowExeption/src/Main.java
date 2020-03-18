import java.util.Scanner;

class Main  {
	public static void main(String[] args) {
		myMethod();
	}

	public static void myMethod() {
		int x, y, z;
		Scanner t = new Scanner(System.in);
		System.out.print("Inserisci due numeri interi x, y e calcolerò il loro rapporto z: ");
		x = t.nextInt();
		y = t.nextInt();
		// Molto brutto e poco elegante perché ArithmeticException esiste già, ma...
		if (y == 0)
			throw new ArithmeticException();
		else {
			z = x / y;
			System.out.println("Tutto ok: z vale " + z);
		}
	}

	public static void otherMethod() {
        int x, y, z;
        Scanner t = new Scanner(System.in);
        System.out.print("Inserisci due numeri interi x, y e calcolerò il loro rapporto z: ");
        try {
            x = t.nextInt();
            y = t.nextInt();
            z = x / y;
            System.out.println("Tutto ok: z vale " + z);
        } catch (ArithmeticException e) {
            System.out.println("Non è possibile dividere per zero");
            // il rilancio dell'eccezione, nel modo più sensato, è quello di farla
            // comunque propagare verso l'alto (o verso il basso se pensiamo allo stack)
            // in modo tale da dare la possibilità ad altri metodi di gestirla a modo loro
            throw e;
        } catch (java.util.InputMismatchException e) {
            System.out.println("Hai inserito almeno un numero in un formato scorretto");
            throw e;
        }
	}
}