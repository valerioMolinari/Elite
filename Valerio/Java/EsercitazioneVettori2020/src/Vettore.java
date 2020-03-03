import java.util.Random;

public class Vettore {
    private int[] v;

    Vettore(int n, int m) {
        v = new int[n];
        Random r = new Random();
        for (int i = 0; i < n; i++)
            v[i] = r.nextInt(m);
    }

    void printArray() {
        System.out.print("vettore = [ ");
        for (int i = 0; i < v.length; i++)
            System.out.print(v[i] + (i == v.length - 1 ? " " : ", "));
        System.out.println("]");
    }

    double average() {
        double m = 0;
        for(int x: v)
            m += x;
        return m/v.length;
    }

    int findFor(int n) {
        for (int i = 0; i < v.length; i++)
            if (v[i] == n)
                return i;
        return -1;
    }

    int findWhile(int n) {
        int count = 0;
        while (v[count] != n) {
            count++;
            if (count == v.length)
                break;
        }
        return count == v.length ? -1 : count;
    }

    int findRick(int n) {
        return findRick(n, 0);
    }

    private int findRick(int n, int i) {
        if (i == v.length)
            return -1;
        if (n == v[i])
            return i;
        return findRick(n, i + 1);
    }

    int timesFor(int n) {
        int count = 0;
        for (int i = 0; i < v.length; i++)
            if (n == v[i])
                count++;
        return count;
    }

    int timesRick(int n) {
        return timesRick(n, 0);
    }

    private int timesRick(int n, int i) {
        if (i == v.length)
            return 0;
        return ( v[i] == n ? 1 : 0) + timesRick(n, i+1);
    }

    int maxFor() {
        int m = 0;
        for (int i = 0; i < v.length; i++)
            if (m <= v[i])
                m = v[i];
        return m;
    }

    int maxRick() {
        return v[maxRick(0)];
    }

    private int maxRick(int i) {
        if (i == v.length - 1)
            return i;
        int max = maxRick(i + 1);
        return v[i] >= v[max] ? i : max;
    }
}
