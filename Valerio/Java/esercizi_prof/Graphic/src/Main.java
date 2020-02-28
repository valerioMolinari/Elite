import java.awt.Graphics;
import java.awt.Font;
import java.awt.Color;
import javax.swing.*;

public class Main {
    // per importare tutto il package:
    /*
    import java.awt.*;
    */
    class Pannello extends JPanel {
        Font f = new Font("TimesRoman", Font.BOLD, 36);
        public void paintComponent (Graphics g) {
        // setBackground(Color.WHITE);
            super.paintComponent(g);
            g.setFont(f);
            g.setColor(Color.RED);
            g.drawString("Hello again!",5,55);
        }
    }

    public class PrimaFinestra extends JFrame
    {
        public PrimaFinestra(String titolo) {
            super(titolo);
            Pannello p = new Pannello();
            add(p);
        }

        public static void main(String[] args) {
            PrimaFinestra finestra = new PrimaFinestra ("Mia applicazione");

            finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            finestra.setBounds(50,300, 400,150);
            finestra.setVisible(true);
        }
    }
}
