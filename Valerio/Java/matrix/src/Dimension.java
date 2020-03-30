public class Dimension  {
    public final int n, m;

    public Dimension(int n, int m) {
        this.n = n;
        this.m = m;
    }

    public boolean equals(Dimension a) {
        return n == a.n && m == a.m;
    }
}