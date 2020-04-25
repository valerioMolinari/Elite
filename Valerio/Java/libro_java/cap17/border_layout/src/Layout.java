import javax.swing.*;
import java.awt.*;

public abstract class Layout extends JFrame {
    public static final int ALTEZZA = 400;
    public static final int LARGHEZZA = 600;

    public Layout(String title, LayoutManager manager) {
        super();
        setSize(LARGHEZZA, ALTEZZA);
        addWindowListener(new QuitEvent());
        setTitle(title);
        costumeLayout(manager);
    }

    public abstract void costumeLayout(LayoutManager manager);
}