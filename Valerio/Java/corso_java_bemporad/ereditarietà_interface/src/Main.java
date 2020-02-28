public class Main {
	public static void main(String[] args) {
		AClass a = new AClass();
		IMyInterface1 mi1 = a;

		mi1.myMethod1();

		System.out.println();

		((IMyInterface2) a).myMethod1();
		((IMyInterface2) a).myMethod2();

		System.out.println();

		System.out.println(mi1);
		System.out.println(a);
	}
}