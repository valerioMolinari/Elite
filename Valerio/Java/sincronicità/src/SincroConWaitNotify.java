public class SincroConWaitNotify {
	public static class ProduttoreWN extends Thread{
		private final DatoScambioWN scambio;

		public ProduttoreWN(DatoScambioWN scambio) {
			this.scambio = scambio;
		}

		@Override
		public void run() {
			while (!isInterrupted())
				synchronized (scambio) {
					scambio.aggiungi();
					System.out.println("Produttore: Inserisco qualcosa nel contenitore");

					scambio.notifyAll(); // avverte gli altri thread che il monitor è libero
					try {
						scambio.wait(); // si mette in attesa rispetto al monitor perché qualcuno lo svegli
					} catch (InterruptedException e) {
						interrupt(); // se il thread viene interrotto mentre è in pausa si solleva un'eccezione che catturiamo bloccando noi stessi il thread
					}
				}
			System.out.println("Produttore: interruzione");
		}
	}

	public static class DatoScambioWN {
		private int valore = 0;

		public void aggiungi() { valore++; }
		public void togli() { valore--; }
		public int getValore() { return valore; }
	}

	public static class ConsumatoreWN extends Thread{
		private final DatoScambioWN scambio;

		public ConsumatoreWN(DatoScambioWN scambio) {
			this.scambio = scambio;
		}

		@Override
		public void run() {
			while (!isInterrupted())
				synchronized (scambio) {
					scambio.togli();
					System.out.println("Consumatore: Tolgo qualcosa nel contenitore");

					scambio.notifyAll();
					try {
						scambio.wait();
					} catch (InterruptedException e) {
						interrupt();
					}
				}
			System.out.println("Consumatore: interruzione");
		}
	}

	public static void main(String[] args) {
		DatoScambioWN datoScambio = new DatoScambioWN();
		ProduttoreWN produttore = new ProduttoreWN(datoScambio);
		ConsumatoreWN consumatore = new ConsumatoreWN(datoScambio);

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
			System.out.println("valore: "+  datoScambio.getValore());
		}
	}
}