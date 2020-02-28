public class Main {
	public static void main(String[] args) {
//		AClass a = new AClass();
//		IMyInterface in = a;
		IMyInterface in = new AClass();
		in.myMethod();
	}
}