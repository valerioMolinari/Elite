import java.io.*;
import java.util.Scanner;

public class ScriviFileBinario  {
	public static void main(String[] args) {
		String file = null;

		try (Scanner input = new Scanner(System.in)) {
			System.out.print("Nome del file da creare: ");
			file = input.nextLine();
		}

		try (FileOutputStream stream = new FileOutputStream(file);
			 DataOutputStream out = new DataOutputStream(new BufferedOutputStream(stream))
		) {
			for (int i = 1; i <= 5; i++)
				out.writeInt(i);
		} catch (IOException e) {
			System.out.println("Errore: " + e.getMessage());
			return;
		}
		System.out.println("File scritto");
	}
}