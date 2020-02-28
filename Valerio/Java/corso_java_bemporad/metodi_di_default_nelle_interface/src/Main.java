public class Main {
	public static void main(String[] args) {
		AClass a = new AClass();
		BClass b = new BClass();
		IMyInterface[] mi = {a,b};
		for (IMyInterface x: mi) {
			x.myMethod1();
			x.myMethod2();
		}
	}
}