import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner tastiera = new Scanner(System.in);
		Vettore v1 = new Vettore(20, 100);

		v1.printArray();
		System.out.println("media: "+v1.average());
		System.out.print("Che numero vuoi cercare: ");
		int n = tastiera.nextInt();
		System.out.println("\nFirstIndex:");
		System.out.println("for: "+v1.findFor(n));
		System.out.println("while: "+v1.findWhile(n));
		System.out.println("Rick: "+v1.findRick(n));
		System.out.println("\nTimes:");
		System.out.println("For: "+v1.timesFor(n));
		System.out.println("Rick: "+v1.timesRick(n));
		System.out.println("\nMax: ");
		System.out.println("For: "+v1.maxFor());
		System.out.println("Rick: "+v1.maxRick());
	}
}