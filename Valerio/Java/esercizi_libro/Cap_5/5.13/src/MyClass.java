import java.util.Scanner;

class MyClass {

	static char cercaCarattere(String s1, String s2) {
		for (int i = 0; i < Math.min(s1.length(), s2.length()); i++)
			if (s1.charAt(i) == s2.charAt(i))
				return s1.charAt(i);
		return '*';
	}

	public static void main(String[] args) {
		Scanner tastiera = new Scanner(System.in);
		String s1, s2;
		char result;
		do {
			System.out.println("Inserisci due stringhe");
			System.out.print("> ");
			s1 = tastiera.nextLine();
			System.out.print("> ");
			s2 = tastiera.nextLine();
			result = cercaCarattere(s1, s2);
			System.out.println(result);
		} while (result != s1.charAt(s1.length() - 1));
	}
}