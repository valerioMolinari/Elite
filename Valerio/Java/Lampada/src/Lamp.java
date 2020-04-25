import java.awt.*;
import javax.swing.*;

public class Lamp extends JFrame {
    public Lamp(String titolo) {
        // titolo è il titolo della finestra
        super(titolo);
        Pannello p = new Pannello();
        // Add può essere usato una volta sola poiché JFrame supporta un componente solo,
        // tuttavia al pannello posso aggiungere tutto ciò che mi pare in modo tale da
        // aggiungere tanti componenti
        add(p);
    }
}