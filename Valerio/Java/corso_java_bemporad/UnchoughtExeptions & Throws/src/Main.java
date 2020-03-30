import java.util.*;

public class Main  {
	public static void main(String[] args) {
        otherMethod();
	}

	public static void myMethod() throws ArithmeticException, InputMismatchException {
	    // Questo metodo può sollevare almeno un'eccezione
        int x, y, z;
        Scanner t = new Scanner(System.in);
        System.out.print("Inserisci due numeri interi x, y e calcolerò il loro rapporto z: ");
        x = t.nextInt();
        y = t.nextInt();
        z = x / y;
        System.out.println("Tutto ok: z vale " + z);
	}

	public static void otherMethod() {
	    try {
            myMethod();
        } catch (ArithmeticException e) {
            System.out.println("La divisione è stata effettuata per 0");
        } catch (InputMismatchException e) {
            System.out.println("Caratteri Inseriti nel formato scorretto");
        }
    }
}