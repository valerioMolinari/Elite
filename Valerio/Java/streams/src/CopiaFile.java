import java.io.*;
import java.util.Scanner;

public class CopiaFile  {
	public static void copia(String sorgente, String destinazione) {
		try (FileInputStream inStream = new FileInputStream(sorgente);
			 DataInputStream input = new DataInputStream(inStream);
			 FileOutputStream outStream = new FileOutputStream(destinazione);
			 DataOutputStream output = new DataOutputStream(outStream);
		) {
			while (true)
				output.writeByte(input.readByte());

		}  catch (FileNotFoundException e) {
			System.out.println("File " + sorgente + " non trovato");
		} catch (EOFException ignored) {
			// con ignored sto dicendo di non fare nulla
		} catch (IOException e) {
			System.out.println("Errore: " + e.getMessage());
		}
	}


	public static void main(String[] args) {
		String sorgente = null;
		String destinazione = null;

		try (Scanner tastiera = new Scanner(System.in)) {
			System.out.print("Inserisci il nome del file sorgente: ");
			sorgente = tastiera.nextLine();
			System.out.print("Inserisci il nome del file destinazione: ");
			destinazione = tastiera.nextLine();
		}

		copia(sorgente, destinazione);
	}
}