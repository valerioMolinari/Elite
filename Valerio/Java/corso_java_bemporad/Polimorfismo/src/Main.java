public class Main {
	public static void main(String[] args) {
		AClass a = new AClass();
		B1Class b1 = new B1Class();
		B2Class b2 = new B2Class();

		a.myMethod();
		b1.myMethod();
		b2.myMethod();

		System.out.println();

		/*
		* L'override dei metodi è importante perché permette il Dynamic Method Dispatch
		* ovvero la scelta dinamica dei metodi. Questa cosa non avviene al livello di compilazione
		* ma al livello di runtime andando a scegliere il metodo in override nell'oggetto puntato
		* piuttosto che quello della variabile che punta. Qui ad esempio viene dichiarato un
		* array di istanze AClass i cui elementi però, tranne a, appartengono a sottoclassi.
		* I parametri a cui possiamo accedere di x sono i parametri a cui si può accedere in AClass,
		* solo che se x punta a b1, il myMethod che eseguirà in runtime è quello di b1
		*/
		AClass[] array = {a, b1, b2};
		for (AClass x: array)
			x.myMethod();
	}
}