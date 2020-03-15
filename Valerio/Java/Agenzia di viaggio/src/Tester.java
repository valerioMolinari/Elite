class Tester  {
	public static void main(String[] args) {
		Archivio archivio = new Archivio(13, 12);
		archivio.visualizza();
		String nome = "Onofrio";
		double d = archivio.worth(nome);
		System.out.printf(d != -1 ? "%s paga %.2f €\n" : "%s non è nostro cliente\n",  nome, d);
	}
}