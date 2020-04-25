import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FinestraPulsanti extends JFrame implements ActionListener {
    public static final int ALTEZZA = 400;
    public static final int LARGHEZZA = 600;
    private Container pannello;

    public FinestraPulsanti() {
        setSize(LARGHEZZA, ALTEZZA);
        addWindowListener(new QuitEvent());
        setTitle("Esempio pulsanti");
        this.pannello = getContentPane();
        pannello.setBackground(Color.BLACK);

        setLayout(new FlowLayout());

        JButton pulsanteStop = new JButton("Rosso");
        pulsanteStop.addActionListener(this);
        add(pulsanteStop);

        JButton pulsanteVia = new JButton("Verde");
        pulsanteVia.addActionListener(this);
        add(pulsanteVia);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "Rosso":
                pannello.setBackground(Color.RED);
                break;
            case "Verde":
                pannello.setBackground(Color.GREEN);
                break;
            default:
                System.out.println("Errore nell'interfaccia");
        }
    }
}