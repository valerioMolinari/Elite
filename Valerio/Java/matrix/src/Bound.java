public class Bound  {
    private int bound;
    private boolean positive;
    private String type;

    public Bound(int bound, boolean positive, String type) {
        this.bound = bound;
        this.positive = positive;
        this.type = type;
    }

    public int getBound() {
        return bound;
    }

    public boolean isPositive() {
        return positive;
    }

    public String getType() {
        return type;
    }
}