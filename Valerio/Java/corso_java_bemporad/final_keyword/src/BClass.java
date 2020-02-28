public final class BClass extends AClass{
    // void myMethod() non è permesso perché il metodo è final nella superclasse
    final double PI = 3.14159;
    // PI non si può riassegnare, final significa const
    void printPI() {
        System.out.println(PI + " is a constant");
    }
}