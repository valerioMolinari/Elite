public class SincroSenzaWaitNotify {
	public static class ProduttoreNWN extends Thread{
		private final DatoScambioNWN scambio;

		public ProduttoreNWN(DatoScambioNWN scambio) {
			this.scambio = scambio;
		}

		@Override
		public void run() {
			while (!isInterrupted())
				synchronized (scambio) {
					scambio.aggiungi();
					System.out.println("ProduttoreNWN: Inserisco qualcosa nel contenitore");
				}
			System.out.println("ProduttoreNWN: interruzione");
		}
	}

	public static class DatoScambioNWN {
		private int valore = 0;

		public void aggiungi() { valore++; }
		public void togli() { valore--; }
		public int getValore() { return valore; }
	}

	public static class ConsumatoreNWN extends Thread{
		private final DatoScambioNWN scambio;

		public ConsumatoreNWN(DatoScambioNWN scambio) {
			this.scambio = scambio;
		}

		@Override
		public void run() {
			while (!isInterrupted())
				synchronized (scambio) {
					scambio.togli();
					System.out.println("ConsumatoreNWN: Tolgo qualcosa nel contenitore");
				}
			System.out.println("ConsumatoreNWN: interruzione");
		}
	}

	public static void main(String[] args) {
		DatoScambioNWN datoScambio = new DatoScambioNWN();
		ProduttoreNWN produttore = new ProduttoreNWN(datoScambio);
		ConsumatoreNWN consumatore = new ConsumatoreNWN(datoScambio);

		produttore.start();
		consumatore.start();
		try {
			Thread.sleep(1000);
			produttore.interrupt();
			consumatore.interrupt();
			produttore.join();
			consumatore.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} finally {
			System.out.println(datoScambio.getValore());
		}
	}
}