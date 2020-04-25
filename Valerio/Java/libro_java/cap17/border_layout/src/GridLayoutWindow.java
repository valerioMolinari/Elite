import javax.swing.*;
import java.awt.*;

public class GridLayoutWindow extends Layout {
    public GridLayoutWindow(String title) {
        super(title, new GridLayout(2, 3));
    }

    @Override
    public void costumeLayout(LayoutManager manager) {
        setLayout(manager);

        JLabel label1 = new JLabel("In alto al centro");
        JLabel label2 = new JLabel("In basso a sinistra");
        JLabel label3 = new JLabel("In basso a destra");

        add(new JLabel(""));
        add(label1);
        add(new JLabel(""));
        add(label2);
        add(new JLabel(""));
        add(label3);
    }
}