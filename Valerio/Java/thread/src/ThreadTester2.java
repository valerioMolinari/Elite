public class ThreadTester2  {
	public static class SimpleTest implements Runnable {
		@Override
		public void run() {
			System.out.println("In thread named: "+Thread.currentThread().getName()+".");
		}
	}

	public static void main(String[] args) {
		SimpleTest aST = new SimpleTest();

		while (true) {
			Thread t = new Thread(aST);
			System.out.println("new Thread() succeeded.");
			t.start();
			try {
				t.join();
			} catch (InterruptedException ignored) {}
		}
	}
}