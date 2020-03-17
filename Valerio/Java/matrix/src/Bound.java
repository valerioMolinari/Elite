public class Bound  {
    private int bound;
    private boolean positive;

    public Bound(int bound, boolean positive) {
        this.bound = bound;
        this.positive = positive;
    }

    public int getBound() {
        return bound;
    }

    public boolean isPositive() {
        return positive;
    }
}