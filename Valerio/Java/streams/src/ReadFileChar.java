import java.io.*;

public class ReadFileChar {
	public static void main(String[] args) {
		String nome = null;
		/*
		* Nel try with resources apriamo il flusso di byte System.in
		* con il metodo InputStreamReader, aspettandoci quindi di ricevere
		* caratteri, quindi creiamo un filtro di lettura caratteri con
		* BufferedReader. Gestiamo poi l'eccezione IOException potenzialmente
		* lanciata da tutti i metodi delle classi InputStream e Reader
		* */
		try (InputStreamReader isr = new InputStreamReader(System.in);
			 BufferedReader tastiera = new BufferedReader(isr)) {
			System.out.print("Nome File da leggere: ");
			nome = tastiera.readLine();
		} catch (IOException e) {
			System.out.println("Errore: " + e.getMessage());
		}

		/*
		* Inizializziamo un contatore n per le righe lette nel file e una
		* variabile di somma s per sommare i numeri ivi contenuti
		* (l'idea è che il file aperto sia file.txt)
		* */

		int n = 0;
		double s = 0;

		/*
		* Apriamo il file di caratteri con FileReader e associamo ad esso
		* un filtro BufferedReader.
		* Dichiariamo la stringa linea quindi effettuiamo un ciclo while
		* sul filtro infile in modo tale da continuare a leggere stringhe
		* fino alla fine, accumulando la somma e contando le linee.
		* Gestiamo naturalmente IOException e l'eventuale FileNotFoundException
		* bloccando, in entrambe, l'esecuzione del programma.
		* Quindi stampiamo a video la somma se il file conteneva righe, altrimenti
		* la dicitura "File vuoto"
		* */
		try (FileReader fr = new FileReader(nome);
			 BufferedReader infile = new BufferedReader(fr)) {
			String linea;
			while ((linea = infile.readLine()) != null) {
				System.out.println(linea);
				s += Double.parseDouble(linea);
				n++;
			}
		} catch (FileNotFoundException e) {
			System.out.println("File " + nome + " non trovato");
			return;
		} catch (IOException e) {
			System.out.println("Errore: " + e.getMessage());
			return;
		}
		System.out.println(n != 0 ? "Media: " + s / n : "File vuoto");
	}
}
