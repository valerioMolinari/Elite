abstract class Veicolo  {
    private int kW;
    private int km;
    private String type;

    Veicolo(int kW) {
        this.kW = kW;
        km = 0;
    }

    Veicolo(int kW, int km) {
        this.kW = kW;
        this.km = km;
    }

    void viaggio(int n) {
        if (n > 0)
            km += n;
    }

    int getkW() {
        return kW;
    }

    int getKm() {
        return km;
    }

    String getType() {
        return type;
    }

    void setType(String type) {
        this.type = type;
    }

    abstract int insurance();
}