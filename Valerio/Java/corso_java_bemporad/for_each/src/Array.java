public class Array {
    private int[] a;
    private int[][] b;
    private int type;

    Array(int t) {
        type = t;
        switch (t) {
            case 1:
                a = new int[5];
                for (int i = 0; i < 5; i++)
                    a[i] = i + 1;
                System.out.println("Array type 1 instantiated");
                break;
            case 2:
                b = new int[5][5];
                for (int i = 0; i < 5; i++)
                    for (int j = 0; j < 5; j++)
                        b[i][j] = i * 5 + j + 1;
                System.out.println("Array type 2 instantiated");
                break;
            default:
                System.out.println("RangeError: type must be 1 orr 2");
        }
    }

    void print() {
       switch (type) {
           case 1:
               for (int n : a)
                   System.out.print(n + " ");
               System.out.println();
               break;
           case 2:
               for (int x[]: b) {
                   for (int n: x)
                       System.out.print(n + " ");
                   System.out.println();
               }
               break;
           default:
               System.out.println("Null");
       }
    }

    private void repeat(char c, int n) {
        for (int i = 0; i < n; i++)
            System.out.print(c);
    }
}
