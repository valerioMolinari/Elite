public class Motocicletta {
    private String marca;
    private String colore;
    private boolean accesa = false;

    public Motocicletta(String marca, String colore) {
        this.marca = marca;
        this.colore = colore;
    }

    public void accendi() {
        if (accesa)
            System.out.println("La "+marca+" è già accesa");
        else {
            accesa = true;
            System.out.println("Ora la "+marca+" è accesa");
        }
    }

    public void spegni() {
        if (!accesa)
            System.out.println("La "+marca+" è già spenta");
        else {
            accesa = false;
            System.out.println("Ora la "+marca+" è spenta");
        }
    }

    public void mostra() {
        System.out.println("Marca: "+marca+"\nColore: "+colore);
    }
}
