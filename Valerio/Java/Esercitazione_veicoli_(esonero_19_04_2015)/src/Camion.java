class Camion extends Veicolo {
    private boolean rimorchio;

    Camion(int kW, boolean rimorchio) {
        super(kW);
        this.rimorchio = rimorchio;
        setType("Camion ");
    }

    Camion(int kW, int km, boolean rimorchio) {
        super(kW, km);
        this.rimorchio = rimorchio;
        setType("Camion ");
    }

    @Override
    int insurance() {
        return getkW() * 1000 + (rimorchio ? 500 : 0) + (getKm() < 50000 ? 500 : 0);
    }
}