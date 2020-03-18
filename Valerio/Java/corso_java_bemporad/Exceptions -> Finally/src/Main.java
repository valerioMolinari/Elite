import java.util.Scanner;

class Main  {
	public static void main(String[] args) {
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
		} catch (java.util.InputMismatchException e) {
			System.out.println("Hai inserito almeno un numero in un formato scorretto");
		} finally {
			// Viene eseguito in ogni caso
			System.out.println("Operazione conclusa");
		}
	}
}