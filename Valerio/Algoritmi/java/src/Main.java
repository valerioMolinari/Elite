import java.util.Random;

public class Main {
	public static void main(String[] args) {
		//MaxSubarray m = new MaxSubarray(newArray(1000000, 100));
		int[] a = Array.newArray(52, 52, false);
		MergeSort m = new MergeSort(a);
		Array.print(a);
		Array.print(m.run());
//		long t = -System.currentTimeMillis();
//		m.run();
//		t += System.currentTimeMillis();
//
//		System.out.println(t);
	}
}