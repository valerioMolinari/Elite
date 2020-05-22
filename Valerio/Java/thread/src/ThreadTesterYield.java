public class ThreadTesterYield  {
	public static class SimpleRun extends Thread {
		@Override
		public void run() {
			while (true) {
				System.out.println("In thread named: "+Thread.currentThread().getName()+".");
				yield();
			}
		}
	}

	public static void main(String[] args) {
		for (int i = 0; i < 10; i++) {
			SimpleRun aSR = new SimpleRun();
			System.out.println("New Thread() succeded");
			aSR.start();
		}
		while (true) {
			System.out.println("Io sono il main");
			Thread.currentThread().yield();
		}
	}
}