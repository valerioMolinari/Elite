import javax.swing.*;

public class PrimaFinestra extends JFrame {
	public static final int ALTEZZA = 400;
	public static final int LARGHEZZA = 600;

	public PrimaFinestra(String label, boolean main) {
		super();

		setSize(LARGHEZZA, ALTEZZA);
		JLabel etichetta = new JLabel(label);

		add(etichetta);

		if (main) {
			DistruttoreFinestra close = new DistruttoreFinestra();
			addWindowListener(close);
		}
	}
}