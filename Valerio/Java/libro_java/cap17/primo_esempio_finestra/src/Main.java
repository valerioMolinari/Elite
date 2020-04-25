import javax.swing.*;

public class Main  {
	public static final int ALTEZZA = 400;
	public static final int LARGHEZZA = 600;

	public static void main(String[] args) {
		// JFrame è un oggetto finestra
		JFrame finestra = new JFrame();
		// .setSize(width, height) ne regola la dimensione
		finestra.setSize(LARGHEZZA, ALTEZZA);

		// Un JLabel è un componente che può essere aggiunto ad una finestra
		JLabel etichetta = new JLabel("Non cliccare quel pulsante!");
		// .add(component) aggiunge un componente
		finestra.add(etichetta);

		// DistruttoreFinestra è una classe che istanzia un listener di chiusura della finestra
		DistruttoreFinestra listener = new DistruttoreFinestra();
		// .addWindowListener() mette la finestra in ascolto di un evento di tipo Window
		finestra.addWindowListener(listener);

		// .setVisible(boolean) rende banalmente visibile o meno una finestra
		finestra.setVisible(true);
	}
}