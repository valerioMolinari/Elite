public class Main extends Object{
	public static void main(String[] args) {
		/*
		* Il metodo equals di Object definito come
		* 	boolean equals(Object object);
		* prende in input un'istanza di Object, ovvero una qualsiasi classe
		* e restituisce, per come è definito, true se i due oggetti sono lo
		* stesso oggetti, ovvero se le due variabili puntano allo stesso oggetto
		*/
		AClass a = new AClass();
		AClass b = new AClass();
		System.out.println(a.equals(b));
		a = b;
		System.out.println(a.equals(b));
		/*
		* Il metodo toString produce una versione stampabile dell'istanza di una classe.
		* Crea una stringa contenente la classe che l'ha istanziata, il carattere @,
		* e l'esadecimale identificativo dell'oggetto. È interessante notare come
		* il metodo venga invocato automaticamente in fase di stampa a video.
		*/
		System.out.println(a.toString());
		System.out.println(a);
	}
}