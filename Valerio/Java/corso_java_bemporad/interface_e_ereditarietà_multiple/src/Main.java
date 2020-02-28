public class Main {
	public static void main(String[] args) {
		AClass a = new AClass();
		BClass b = new BClass();

		((IMyInt1) a).myMethod();
		((IMyInt2) a).myMethod();
		System.out.println();
		((IMyInt2) b).myMethod();
		((IMyInt3) b).myMethod();
	}
}