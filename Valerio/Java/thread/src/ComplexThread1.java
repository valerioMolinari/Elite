public class ComplexThread1 extends Thread {
	public ComplexThread1(String name) {
		super(name);
	}

	@Override
	public void run() {
		while(true)
			System.out.println(Thread.currentThread().getName());
	}

	public static void main(String[] args) {
		System.out.println(Thread.currentThread().getName());
		new ComplexThread1("Patata uno").start();
		new ComplexThread1("Patata due").start();
		System.out.println(Thread.currentThread().getName());
	}
}
