public interface IMyInterface {
    void myMethod1();
    default void myMethod2() {
        System.out.println("myMethod2 in IMyInterface");
    }
}