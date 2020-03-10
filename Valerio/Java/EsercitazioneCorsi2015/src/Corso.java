abstract class Corso  {
    private int partecipanti, durata;

    Corso(int partecipanti, int durata) {
        this.partecipanti = partecipanti;
        this.durata = durata;
    }

    void iscrivi(int n) { partecipanti += n; }

    public int getPartecipanti() { return partecipanti; }

    public int getDurata() { return durata; }

    String getType() {
        String s = this.toString();
        return s.substring(0, s.indexOf("@"));
    }

    abstract int costoIscrizione();
}