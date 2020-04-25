public class Main  {
	public static void main(String[] args) {
		PrimaFinestra finestraPrincipale = new PrimaFinestra("Finestra principale", true);
		finestraPrincipale.setVisible(true);

		PrimaFinestra finestraSecondaria = new PrimaFinestra("Finestra secondaria", false);
		finestraSecondaria.setVisible(true);
	}
}