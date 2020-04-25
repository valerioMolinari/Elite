import javax.swing.*;

public class Main  {
	public static void main(String[] args) {
		Lamp finestra = new Lamp("Mia Finestra");
		// Questo fa si che l'applicazione termini quando clicco sulla x
		finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		// Distanza dall'angolo in alto a sinistra, larghezza, altezza
		finestra.setBounds(50, 300, 300, 330);
		finestra.setVisible(true);
	}
}