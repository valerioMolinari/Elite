class Tester  {
	public static void main(String[] args) {
		Oasi o = new Oasi(30);
		o.visualizza();
		System.out.println("Il " + o.piuCostoso()[1] + " " + o.piuCostoso()[0] + " è l'animale più costoso da mantenere");
	}
}