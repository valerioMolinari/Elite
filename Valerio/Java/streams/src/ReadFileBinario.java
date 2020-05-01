import java.io.*;
import java.util.Scanner;

public class ReadFileBinario {
	public static void main(String[] args) {
		String nome = null;
		int n = 0;
		double s = 0;

		try (Scanner input = new Scanner(System.in)) {
			System.out.print("Nome del file binario da leggere: ");
			nome = input.nextLine();
		}

		try (FileInputStream bin = new FileInputStream(nome);
			 BufferedInputStream bis = new BufferedInputStream(bin);
			 DataInputStream input = new DataInputStream(bis);
		) {
			int dato;
			while (true) {
				dato = input.readInt();
				System.out.println(dato);
				s += dato;
				n++;
			}
		}  catch (EOFException e) {
			System.out.println("\tLetta fine file");
		} catch (FileNotFoundException e) {
			System.out.println("File " + nome + " non trovato");
			return;
		} catch (IOException e) {
			System.out.println("Errore: " + e.getMessage());
			return;
		}
		System.out.println(n != 0 ? "Media: " + s/n : "File vuoto");
	}
}