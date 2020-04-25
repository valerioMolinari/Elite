import java.awt.*;

public class Main  {
	public static void main(String[] args) {
		SecondaFinestra finestraPrincipale = new SecondaFinestra("Finestra principale", "Colore di default", true);
		finestraPrincipale.setVisible(true);

		SecondaFinestra finestraSecondaria = new SecondaFinestra("Finestra secondaria", "Colore personalizzato", Color.LIGHT_GRAY, false);
		finestraSecondaria.setVisible(true);
	}
}