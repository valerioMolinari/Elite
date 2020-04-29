import java.io.*;

public class MediaFileChar  {
	public static void main(String[] args) {
		String nome = null;
		try (InputStreamReader isr = new InputStreamReader(System.in);
			 BufferedReader tastiera = new BufferedReader(isr)) {
			System.err.print("Nome File da leggere: ");
			nome = tastiera.readLine();
		} catch (IOException e) {
			System.err.println("Errore: " + e.getMessage());
		}

		int n = 0;
		double s = 0;

		try (FileReader fr = new FileReader(nome);
			 BufferedReader infile = new BufferedReader(fr)) {
			String linea;
			while ((linea = infile.readLine()) != null) {
				System.out.println(linea);
				s += Double.parseDouble(linea);
				n++;
			}
		} catch (FileNotFoundException e) {
			System.err.println("File " + nome + " non trovato");
			return;
		} catch (IOException e) {
			System.err.println("Errore: " + e.getMessage());
			return;
		}
		System.out.println(n != 0 ? "Media: " + s / n : "File vuoto");
	}
}