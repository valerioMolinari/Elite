public class Main  {
	public static void main(String[] args) {
		Array a = new Array(1000, 10000000);
		long t = -System.currentTimeMillis();
		a = a.bubbleSort("a");
		t += System.currentTimeMillis();
		a.visualizza();
		System.out.println(t);
	}
}