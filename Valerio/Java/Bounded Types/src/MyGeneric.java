public class MyGeneric<T extends Number>  {
    private T t;

    public MyGeneric(T t) {
        this.t = t;
    }

    public T getT() {
        return t;
    }

    public int quadrato() {
        return t.intValue() * t.intValue();
    }
}