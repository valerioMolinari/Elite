import java.util.ArrayList;

public class Cellphone  {
	private String gestore;
	private String numero;
	private static ArrayList<Configuration> configs = new ArrayList<>();

	private static class Configuration {
		private String gestoreDiPartenza;
		private String gestoreDiArrivo;
		private double cost;

		public Configuration(String gestoreDiPartenza, String gestoreDiArrivo, double cost) {
			this.gestoreDiPartenza = gestoreDiPartenza;
			this.gestoreDiArrivo = gestoreDiArrivo;
			this.cost = cost;
		}
	}

	public Cellphone(String gestore, String numero) {
		this.gestore = gestore;
		this.numero = numero;
	}

	public static void setCost(String gestoreDiPartenza, String gestoreDiArrivo, double costo) {
		configs.add(new Configuration(gestoreDiPartenza, gestoreDiArrivo, costo));
	}

	public double getCost(Cellphone target, int min) throws Exception {
		for(Configuration c : configs)
			if (c.gestoreDiPartenza.equals(gestore) && c.gestoreDiArrivo.equals(target.gestore))
				return min * c.cost;
		throw new Exception("Chiamata non possibile tra le due linee");
	}

	public static void main(String[] args) throws Exception {
		Cellphone a = new Cellphone("TIMMY", "3341234"),
				b = new Cellphone("Megafon", "3355678"),
				c = new Cellphone("Odissey", "3384343");
		Cellphone.setCost("TIMMY", "TIMMY", 0.05);
		Cellphone.setCost("TIMMY", "Megafon", 0.15);
		Cellphone.setCost("Megafon", "TIMMY", 0.25);
		System.out.println(a.getCost(b, 10));
		System.out.println(b.getCost(a, 8));
		System.out.println(a.getCost(c, 10));
	}
}