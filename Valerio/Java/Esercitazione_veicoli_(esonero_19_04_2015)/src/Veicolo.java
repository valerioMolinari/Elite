abstract class Veicolo  {
    protected int kW;
    private int km;

    public Veicolo(int kW) {
        this.kW = kW;
        km = 0;
    }

    public Veicolo(int kW, int km) {
        this.kW = kW;
        this.km = km;
    }

    public void viaggio(int n) {
        if (n > 0)
            km += n;
    }

    public int getKm() {
        return km;
    }

    public abstract int assicurazione();

    public String getType() {
        return getClass().getCanonicalName();
    }
}