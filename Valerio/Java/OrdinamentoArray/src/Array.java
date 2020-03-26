import java.util.Random;

public class Array  {
    private int[] array;

    public Array(int n, int bound) {
        Random r = new Random();
        array = new int[n];
        for (int i = 0; i < n; i++)
            array[i] = r.nextInt(bound);
    }

    public Array(int[] array) {
        this.array = array;
    }

    public void visualizza() {
        for (int x : array)
            System.out.print(x + " ");
        System.out.println("\n");
    }

    public Array bubbleSort(String type) {
        int[] ordered = array.clone();
        int temp;
        int last = 0;
        if (!(type.equals("a") || type.equals("d")))
            return new Array(ordered);
        for (int i = 0; i < ordered.length - 1; i++) {
            for (int j = ordered.length - 1; j > i; j--) {
                if (type.equals("a") ? ordered[j] > ordered[j - 1] : ordered[j] < ordered[j - 1]) {
                    temp = ordered[j];
                    ordered[j] = ordered[j - 1];
                    ordered[j - 1] = temp;
                    last = j - 1;
                }
            }
            if ( i < last)
                i = last;
        }

        return new Array(ordered);
    }
}