import javax.swing.*;
import java.awt.Color;
import java.awt.Container;

public class SecondaFinestra extends JFrame {
    public static final int ALTEZZA = 400;
    public static final int LARGHEZZA = 600;

    public SecondaFinestra(String title, String label, boolean main) {
        super();
        settings(title, label, Color.BLUE, main);
    }

    public SecondaFinestra(String title, String label, Color colore, boolean main) {
        super();
        settings(title, label, colore, main);
    }

    private void settings(String title, String label, Color colore, boolean main) {
        setSize(LARGHEZZA, ALTEZZA);

        JLabel etichetta = new JLabel(label);
        add(etichetta);

        setTitle(title);

        Container pannelloDelContenuto = getContentPane();
        pannelloDelContenuto.setBackground(colore);

        if (main)
            addWindowListener(new DistruttoreFinestra());
    }
}