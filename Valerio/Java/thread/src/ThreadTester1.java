public class ThreadTester1  {
	public static class SimpleRunnable extends Thread {
		@Override
		public void run() {
			System.out.println("In thread named: "+Thread.currentThread().getName()+".");
		}
	}

	public static void main(String[] args) {

		while (true) {
			SimpleRunnable aSR = new SimpleRunnable();
			System.out.println("new Thread() " + (aSR.equals(null) ? "fail" : "succeed") + "ed.");
			aSR.start();
		}
	}
}