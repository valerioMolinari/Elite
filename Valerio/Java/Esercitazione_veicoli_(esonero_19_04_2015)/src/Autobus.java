class Autobus extends Veicolo {
    private int passengers;

    public Autobus(int kW, int passengers) {
        super(kW);
        this.passengers = passengers;
    }

    public Autobus(int kW, int km, int passengers) {
        super(kW, km);
        this.passengers = passengers;
    }

    @Override
    public int assicurazione() {
        return kW * 750 + (passengers > 50 ? 1000 : 0) + (getKm() > 20000 ? 200 : 0);
    }
}