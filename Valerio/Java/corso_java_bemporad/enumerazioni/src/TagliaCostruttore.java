enum TagliaCostruttore {
    EXTRASMALL(1), SMALL(2), MEDIUM(3), LARGE(4), EXTRALARGE(5);

    private int valore;

    TagliaCostruttore(int valore) {
        this.valore = valore;
    }

    int getValore() {
        return valore;
    }
}