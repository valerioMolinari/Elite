public class ContaIPaperini  {
	public static class ContoCorrenteCS {
		private double c = 0;

		public synchronized void incrementa() { c += 1; }
		public synchronized void decrementa() { c -= 1; }
		public double saldo() { return c; };
	}

	public static class ThreadCounter {
		private int count = 0;

		public synchronized void contami() { count++; }
		public int quanti() { return count; }
	}

	public static class PaperinoCS extends Thread{
		private ContoCorrenteCS c;

		public PaperinoCS(String nome, ContoCorrenteCS c, ThreadCounter contatore) {
			super(nome);
			this.c = c;
			contatore.contami();
			System.out.println(getName() + " è stato istanziato");
		}

		@Override
		public void run() {
			for(int i = 0; i < 20; i++) {
				c.incrementa();
				System.out.println(getName() + " ha incrementato");
			}
		}
	}

	public static void main(String[] args) {
		PaperinoCS[] paperini = new PaperinoCS[20];
		ThreadCounter counter = new ThreadCounter();
		ContoCorrenteCS c = new ContoCorrenteCS();

		for (int i = 0; i < 20; i++) {
			paperini[i] = new PaperinoCS("paperino" + i, c, counter);
			paperini[i].start();
		}

		try {
			for (int i = 0; i < 20; i++)
				paperini[i].join();
		} catch (InterruptedException e) {e.printStackTrace();}

		System.out.println("\nSaldo:\t\t" + c.saldo());
		System.out.println("Contatore:\t" + counter.quanti());
	}
}