public class BClass extends AClass {
    void myMethod() {
        System.out.println("myMethod in BClass");
    }

    void myDecoration() {
        super.myDecoration();
        System.out.println("Ok this method just been redecorated in BClass");
    }

    void myOverload(int x) {
        System.out.println("Overload in BClass");
    }
}