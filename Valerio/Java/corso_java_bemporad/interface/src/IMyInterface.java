public interface IMyInterface {
    /*
    * Tutti i metodi di un'interface hanno visibilità public quindi non dobbiamo specificarli.
    *
    * Se una classe che implementa un'interface non definisce tutti i metodi dell'interface,
    * tale classe va dichiarata abstract e per tanto non può più essere istanziata
    */
    void myMethod1();
    void myMethod2();
    /*
    * Un'interface, raramente, può contenere anche delle variabili, ma queste vengono
    * implicitamente dechiarate con i modificatori public final static, quindi
    * membri di classe costanti e pubblici, questo implica che vanno inizializzate
    * immediatamente
    */
    int CONST = 10;
    String MSD = "Message";
}