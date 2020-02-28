public class Main {
	public static void main(String[] args) {
		AClass a = new AClass();
		BClass b = new BClass();
		// Override
		a.myMethod();
		b.myMethod();
		System.out.println();
		// Decorazione
		b.myDecoration();
		System.out.println();
		// Overload
		b.myOverload();
		b.myOverload(10);
	}
}