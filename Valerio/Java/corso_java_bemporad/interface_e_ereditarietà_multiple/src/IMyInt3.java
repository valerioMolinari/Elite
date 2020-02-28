public interface IMyInt3 extends IMyInt2 {
    default void myMethod() {
        System.out.println("myMethod in IMyInt3");
    }
}