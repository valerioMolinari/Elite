public class MyException extends Exception {

    // toString() è di Object, il messaggio dell'eccezione è scritto in toString
    @Override
    public String toString() {
        return "Eccezione Personalizzata! 😃";
    }
}