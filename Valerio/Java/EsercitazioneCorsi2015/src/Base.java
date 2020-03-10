class Base extends Corso {
    private int laboratorio;

    Base(int partecipanti, int durata, int laboratorio) {
        super(partecipanti, durata);
        this.laboratorio = laboratorio;
    }

    @Override
    int costoIscrizione() {
        return 1000 + (getPartecipanti() < 100 ? 500 : 0) + (laboratorio > 50 ? 500 : 0);
    }
}