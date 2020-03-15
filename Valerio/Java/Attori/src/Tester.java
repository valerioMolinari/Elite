class Tester  {
	public static void main(String[] args) {
		Archivio a = new Archivio(30);
		a.visualizza();
		double d = 15;
		System.out.println(a.migliori(d) + " attori hanno un gradimento maggore di " + d);
	}
}