import java.awt.event.*;

public class DistruttoreFinestra extends WindowAdapter {
    @Override
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
}