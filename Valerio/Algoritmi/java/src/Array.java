import java.util.Random;

public class Array {
    public static int[] newArray(int size, int bound) {
        return newArray(size, bound, true);
    }

    public static int[] newArray(int size, int bound, boolean signed) {
        Random r = new Random();
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            if (signed)
                array[i] = r.nextInt(bound * 2) - bound;
            else
                array[i] = r.nextInt(bound);
        return array;
    }

    public static void print(int[] a) {
        System.out.print('[');
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + (i < a.length - 1 ? ", " : ""));
        System.out.println(']');
    }
}