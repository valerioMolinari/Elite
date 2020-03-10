class Tester  {
	public static void main(String[] args) {
		Segreteria unipg = new Segreteria(10, 5);
		unipg.stampaArray();
		int tetto = 2000;
		System.out.println("I corsi il cui prezzo è inferiore a " + tetto + "€ sono " + unipg.corsiSostenibili(tetto));
	}
}