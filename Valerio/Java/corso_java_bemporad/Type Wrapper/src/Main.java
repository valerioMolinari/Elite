class Main  {
	public static void main(String[] args) {
		/*
		* I type wrappers sono involucri in cui è possibile includere un tipo primitivo
		* e sono definiti in java.lang
		*
		* Questi sono
		* 	Integer
		* 	Double
		* 	Float
		* 	Short
		* 	Long
		* 	Byte
		* 	Character
		* 	Boolean
		*
		* Innanzti tutto concentriamoci sui primi 6 che sono sottoclassi  della classe Number
		*
		* ciascuna di queste classi possiedono un particolare metodo statico che si chiama
		* valueOf che prende un valore e restituisce un'istanza di tipo wrapper:
		*
		* static Integer valueOf(int value)
		*
		*
		* */

		int x = 10;
		Integer ox = Integer.valueOf(x);
		String y = "50";
		Integer oy = Integer.valueOf(y);

		/*
		* Questo meccanismo prende il nome di boxing
		*
		* È possibile anche fare il procedimento inverso, ovvero l'unboxing
		* */

		x = ox.intValue();

		/*
		* È possibile eseguire questi procedimenti in maniera automatica, ovvero
		* auto-boxing e auto-unboxing
		*
		* */

		Integer ox2 = 10;
		int x2 = ox2;

		// auto-boxing automatico
		myMethod(10);

	}

	public static void myMethod(Integer ox) {
		// auto-unboxing automatico
		System.out.println(ox);
	}
}