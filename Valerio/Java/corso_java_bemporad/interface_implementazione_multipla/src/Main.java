public class Main {
	public static void main(String[] args) {
		AClass a = new AClass();
		CClass c = new CClass();
		IMyInterface2[] mi2 = {a, c};
		for (IMyInterface2 x: mi2)
			x.myMethod2();
	}
}