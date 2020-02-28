import java.util.Scanner;

class ShiftaStringhe {
	static String shift(String daShiftare, int positions) {
		positions %= daShiftare.length();
		return daShiftare.substring(positions).concat(daShiftare.substring(0, positions));
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String string;
		int n;
		do {
			System.out.print("Inserisci una parola: ");
			string = s.nextLine();
			System.out.print("Inserisci le posizioni da shiftare: ");
			n = s.nextInt();
			s.nextLine();
			string = shift(string, n);
			System.out.println(string);
		} while (!(string.startsWith("a") && string.endsWith("a")));
	}
}