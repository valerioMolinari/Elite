/*
* Si realizzi una classe java che definisce:
* a: il metodo cercaCarattere che accetta in ingresso due stringhe, confronta a
* 	 uno ad uno i caratteri delle due stringhe e restituisce il primo carattere
* 	 uguale trovato oppure restituisce il carattere '*' se le due stringhe
* 	 non hanno nemmeno un carattere uguale.
* b: il metodo main che continua a leggere in input due stringhe e invoca il
* 	 metodo cercaCarattere passandogli le stringhe inserite dall'utente,
* 	 finché il carattere restituito dal metodo è diverso dall'ultimo carattere
* 	 della prima stringa
*/

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