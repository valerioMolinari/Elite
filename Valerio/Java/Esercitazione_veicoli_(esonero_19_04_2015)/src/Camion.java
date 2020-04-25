class Camion extends Veicolo {
    private boolean rimorchio;

    public Camion(int kW, boolean rimorchio) {
        super(kW);
        this.rimorchio = rimorchio;
    }

    public Camion(int kW, int km, boolean rimorchio) {
        super(kW, km);
        this.rimorchio = rimorchio;
    }

    @Override
    public int assicurazione() {
        return kW * 1000 + (rimorchio ? 500 : 0) + (getKm() > 50000 ? 500 : 0);
    }
}