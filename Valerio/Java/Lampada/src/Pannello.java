import javax.swing.*;
import java.awt.*;

public class Pannello extends JPanel {
    public void paintComponent(Graphics g) {
        setBackground(Color.WHITE);
        super.paintComponent(g);
        g.setColor(Color.BLACK);

        // la piattaforma della lampada
        g.fillRect(0, 270, 300, 40);

        // la base della lampada
        g.drawLine(125, 270, 125, 160);
        g.drawLine(175, 270, 175, 160);
        g.drawOval(50, 160, 200, 50);

        g.drawLine(50, 182, 90, 50);
        g.drawLine(250, 182, 210, 50);
        g.drawArc(90, 40, 120, 20, 0, 180);
    }
}