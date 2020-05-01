import java.io.*;
import java.util.Scanner;

public class ReadFileScanner {
	public static void main(String[] args) {
		String file = null;
		int n = 0;
		double s = 0;

		try (Scanner tastiera = new Scanner(System.in)) {
			System.out.print("Nome del file da leggere: ");
			file = tastiera.nextLine();
		}

		try (FileReader stream = new FileReader(file);
			 Scanner input = new Scanner(stream)
		) {
			double number;
			while (input.hasNextDouble()) {
				number = input.nextDouble();
				System.out.println(number);
				s += number;
				n++;
			}
		} catch (IOException e) {
			System.out.println("Errore: " + e.getMessage());
		}

		System.out.println(n != 0 ? "Media: " + s / n : "File vuoto");
	}
}