public class MyClass {
    void vargs(int ... arg) {
        System.out.print(arg.length + "Parametri interi: ");
        for (int a : arg) System.out.print(a + " ");
        System.out.println();
    }
    void vargs(double ... arg) {
        System.out.print(arg.length + "Parametri double: ");
        for (double a : arg) System.out.print(a + " ");
        System.out.println();
    }
}
