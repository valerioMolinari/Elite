public class ContoCorrente_sincronicitaGestita  {
	public static class ContoCorrenteS {
		private double c = 0;

		public synchronized void incrementa() { c += 1; }
		public synchronized void decrementa() { c -= 1; }
		public double saldo() { return c; };
	}

	public static class PaperoneS extends Thread {
		private ContoCorrenteS c;

		public PaperoneS(ContoCorrenteS c) {
			this.c = c;
		}

		@Override
		public void run() {
			for(int i = 0; i < 20_000_000; i++)
				c.incrementa();
		}
	}

	public static class PaperinoS extends Thread {
		private ContoCorrenteS c;

		public PaperinoS(ContoCorrenteS c) {
			this.c = c;
		}

		@Override
		public void run() {
			for(int i = 0; i < 20_000_000; i++)
				c.decrementa();
		}
	}

	public static void main(String[] args) {
		ContoCorrenteS c = new ContoCorrenteS();
		Thread paperino = new PaperinoS(c);
		Thread paperone = new PaperoneS(c);

		paperino.start();
		paperone.start();

		try {
			paperino.join();
			paperone.join();
		} catch (InterruptedException e) { e.printStackTrace(); }

		System.out.println(c.saldo());
	}
}