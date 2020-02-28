public class AClass extends Object {
    /*
    * Ogni classe che creiamo in Java, sono implicitamente sottoclassi della superclasse Object,
    * in cui alcuni metodi sono definiti final, come ad esempio .equals e .toStringò
    * Scrivere che qualcosa estende Object quindi è corretto ma inutile.
    */
    void myMethod() {
        System.out.println("myMethod in AClass");
    }
}