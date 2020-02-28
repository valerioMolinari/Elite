public class Main {
	public static void main(String[] args) {
		// AClass a = new AClass(); <- Le classi astratte non possono essere istanziate
		B1Class b1 = new B1Class();
		B2Class b2 = new B2Class();
		C1Class c1 = new C1Class();

		AClass[] a = {b1, b2, c1};
		for (AClass x: a)
			x.myMethod();
	}
}