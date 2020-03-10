class Avanzato extends Corso {
    private boolean tirocinio;

    Avanzato(int partecipanti, int durata, boolean tirocinio) {
        super(partecipanti, durata);
        this.tirocinio = tirocinio;
    }

    @Override
    int costoIscrizione() {
        return 2000 + (getPartecipanti() < 50 ? 500 : 0) + (tirocinio ? 500 : 0);
    }
}