import javax.swing.*;
import java.awt.*;

public class BorderLayoutWindow extends Layout {
    public BorderLayoutWindow(String title) {
        super(title, new BorderLayout());
    }

    @Override
    public void costumeLayout(LayoutManager manager) {
        // Per selezionare un gestore di layout occorre aggiungerlo con questa istruzione
        setLayout(manager);

        JLabel etichetta1 = new JLabel("La prima etichetta in alto");
        JLabel etichetta2 = new JLabel("La seconda etichetta in basso");
        JLabel etichetta3 = new JLabel("La terza etichetta al centro");
//      JLabel etichetta4 = new JLabel("La quarta etichetta a destra");
//      JLabel etichetta5 = new JLabel("La quinta etichetta a sinistra");

        add(etichetta1, BorderLayout.NORTH);
        add(etichetta2, BorderLayout.SOUTH);
        add(etichetta3, BorderLayout.CENTER);
//      add(etichetta4, BorderLayout.EAST);
//      add(etichetta5, BorderLayout.WEST);
    }
}