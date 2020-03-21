class Main  {
	public static void main(String[] args) {
		/*
		* I Generics sono i tipi parametrici, ovvero classi, interface, metodi
		* specificati tramite parametri
		* */

		MyClasseObject mco = new MyClasseObject();
		mco.setObj("Java language");
		String s = (String) mco.getObj();
		System.out.println(s);

		mco.setObj(150);
		int n = (int) mco.getObj();
		System.out.println(n);

		try {
			mco.setObj(150);
			s = (String) mco.getObj();
			System.out.println(s);
		} catch (java.lang.ClassCastException e) {
			System.out.println("\033[91mException in thread \"main\" java.lang.ClassCastException: class java.lang.Integer cannot be cast to class java.lang.String");
		}

		MyGeneric<String> strGen = new MyGeneric<>();
		strGen.setT("Java language");
		String str = strGen.getT();
		System.out.println(str);

		MyGeneric<Integer> intGen = new MyGeneric<>();
		intGen.setT(150);
		int i = intGen.getT();
		System.out.println(i);
	}
}