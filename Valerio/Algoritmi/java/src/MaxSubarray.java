import java.util.*;

public class MaxSubarray {
    private final int[] A;

    public MaxSubarray(int[] a) {
        A = a;
    }

    public int[] run() {
        int max = 0, sum;
        int start = 0, end = 0;
        ArrayList<Integer> change = new ArrayList<>();
        ArrayList<Integer> sums = new ArrayList<>();

        change.add(0);

        for (int i = 0; i < A.length - 1; i++)
            if (A[i] * A[i + 1] < 0)
                change.add(i + 1);

        change.add(A.length);

        for (int i = 0; i < change.size() - 1; i++) {
            sum = 0;
            for (int j = change.get(i); j < change.get(i + 1); j++)
                sum += A[j];
            sums.add(sum);
        }

        for (int i = 0; i < sums.size(); i++) {
            sum = 0;
            for (int j = i; j < sums.size(); j++) {
                sum += sums.get(j);
                if (sum > max) {
                    max = sum;
                    start = change.get(i);
                    end = change.get(j + 1);
                }
            }
        }

        return Arrays.copyOfRange(A, start, end);
    }
}