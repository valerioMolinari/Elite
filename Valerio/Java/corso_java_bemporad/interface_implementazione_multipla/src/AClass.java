public class AClass implements IMyInterface1, IMyInterface2 {
    @Override
    public void myMethod1() {
        System.out.println("myMethod1 in AClass");
    }

    @Override
    public void myMethod2() {
        System.out.println("myMethod2 in AClass");
    }
}