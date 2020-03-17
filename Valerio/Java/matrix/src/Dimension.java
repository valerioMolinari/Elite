public class Dimension  {
    private int n, m;

    public Dimension(int n, int m) {
        this.n = n;
        this.m = m;
    }

    public int getN() {
        return n;
    }

    public int getM() {
        return m;
    }

    public boolean equals(Dimension a) {
        return n == a.n && m == a.m;
    }
}