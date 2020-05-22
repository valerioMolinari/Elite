public class ContoCorrente_sincronicitaNonGestita  {
	public static class ContoCorrente {
		private double c = 0;

		public void incrementa() { c += 1; }
		public void decrementa() { c -= 1; }
		public double saldo() { return c; };
	}

	public static class Paperone extends Thread {
		private ContoCorrente c;

		public Paperone(ContoCorrente c) {
			this.c = c;
		}

		@Override
		public void run() {
			for(int i = 0; i < 20_000_000; i++)
				c.incrementa();
		}
	}

	public static class Paperino extends Thread {
		private ContoCorrente c;

		public Paperino(ContoCorrente c) {
			this.c = c;
		}

		@Override
		public void run() {
			for(int i = 0; i < 20_000_000; i++)
				c.decrementa();
		}
	}

	public static void main(String[] args) {
		ContoCorrente c = new ContoCorrente();
		Thread paperino = new Paperino(c);
		Thread paperone = new Paperone(c);

		paperino.start();
		paperone.start();

		try {
			paperino.join();
			paperone.join();
		} catch (InterruptedException e) { e.printStackTrace(); }

		System.out.println(c.saldo());
	}
}