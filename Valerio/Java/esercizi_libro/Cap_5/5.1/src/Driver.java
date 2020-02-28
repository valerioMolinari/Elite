/*
* Si realizzi una classe Java in cui è definito il metodo confronta che accetta in
* ingresso due interi e restituisce il primo meno il secondo se il primo è maggiore
* del secondo, oppure restituisce il secondo meno il primo. Scrivere quindi un programma
* driver per collaudare il metodo
*/

class Driver {
	public static void main(String[] args) {
		MyClass m = new MyClass();
		System.out.println(m.confronta(5, 9));
		System.out.println(m.confronta(8, 3));
		System.out.println(m.confronta(12, 12));
	}
}