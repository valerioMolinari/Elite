class Autobus extends Veicolo {
    private int passengers;

    Autobus(int kW, int passengers) {
        super(kW);
        this.passengers = passengers;
        setType("Autobus");
    }

    Autobus(int kW, int km, int passengers) {
        super(kW, km);
        this.passengers = passengers;
        setType("Autobus");
    }

    @Override
    int insurance() {
        return getkW() * 750 + (passengers > 50 ? 1000 : 0) + (getKm() > 20000 ? 200 : 0);
    }
}