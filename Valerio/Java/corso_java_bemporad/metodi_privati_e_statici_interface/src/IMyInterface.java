public interface IMyInterface {
    // Deve contenere codice
    // Serve a preserevare il concetto di incapsulamento grazie all'esistenza dei metodi
    // di default
    private void privMethod() {
        System.out.println("privMethod in IMyInterface");
    }

    default void myMethod() {
        privMethod();
        System.out.println("myMethod in IMyInterface");
    }

    static void myStaticMethod() {
        System.out.println("myStaticMethod in IMyInterface");
    }
}