public class MyClass {
    void vargs(int ... arg) {
        System.out.print("Parametri: ");
        for (int a : arg) System.out.print(a + " ");
        System.out.println();
    }
}
