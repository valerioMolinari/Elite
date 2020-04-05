import java.util.LinkedList;

public class Main  {
	public static <T> LinkedList<T> merge(LinkedList<T> list1, LinkedList<T> list2) {
		if (list1.size() != list2.size())
			throw new IllegalArgumentException();

		LinkedList<T> mergedList = new LinkedList<>();
		for (int i = 0; i < list1.size(); i++) {
			mergedList.add(list1.get(i));
			mergedList.add(list2.get(i));
		}

		return mergedList;
	}

	public static void main(String[] args) {
		LinkedList<Integer> l1 = new LinkedList<>();
		LinkedList<Integer> l2 = new LinkedList<>();
		l1.add(1);
		l1.add(2);
		l1.add(3);
		l2.add(4);
		l2.add(5);
		l2.add(6);
		var merged = merge(l1, l2);
		for (Integer integer : merged)
			System.out.print(integer + " ");
		System.out.println();
	}
}