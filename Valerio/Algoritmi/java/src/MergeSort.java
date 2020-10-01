@NotWorking

public class MergeSort {
    private final int[] A;

    public MergeSort(int[] a) {
        A = a;
    }

    public int[] run() {
        return run(A, 0, A.length);
    }

    private int[] run(int[] a, int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;
            run(a, p, q);
            run(a, q + 1, r);
            merge(a, p, q, r);
        }
        return a;
    }

    private void merge(int[] a, int p, int q, int r) {
//        System.out.println(p + " " + q + " " + r);
//        System.exit(0);
        int n1 = q - p + 1;
        int n2 = r - q;
        int i,j;
        int[] L = new int[n1 + 1];
        int[] R = new int[n2 + 1];
        for (i = 0; i < n1; i++)
            L[i] = a[p + i];
        for (j = 0; j < n2; j++)
            R[j] = a[q + j + 1];
        int sentinel = (int) Math.pow(2, 31);
        L[n1] = R[n2] = sentinel;
//        Array.print(L);
//        Array.print(R);
//        if (r > 4)
//            System.exit(0);
        i = j = 0;
        for (int k = p; k < r; k++) {
            if (L[i] <= R[j]) {
                a[k] = L[i];
                i++;
            } else {
                a[k] = R[j];
                j++;
            }
        }
    }
}