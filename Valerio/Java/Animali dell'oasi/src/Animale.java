import java.util.Random;

public abstract class Animale  {
    // Attributi di classe
    private static String[][] nomi = {
            {"Iperico","Xandra","Ciottolino","Storm","Diana","Winnie","Ungus","Hannibal","Tulula","Red","Gypsy","Olivella","Lynx","Akira","Blu","Curry","Turbo","Foxy","Peace","Tequila","Angel","Athos","Ettore","Pegasus","Chris","Milady","Atomo","Havana","Wakko","Utopia","Xiomara","Tammy","Ysolde","Harley","Nabucco","Jemma","Dagon","Furry","Tennessee","Jet","Elwood","Pallino","Bilbo","Jet","Rusty","Xerox","Woody","Erik","Yaro","Indiana","Batuffolo","Wooster","Tyson","Rose","Ink","Zehira","Jade","Annie","Wellie","Diamond","Fairy","Jimmy","Apollo","Karma","Bach","Kairy","Jessie","Keira","Harvey","Pussy","Happy","Quistador","Josie","Sophie","Schizzo","Willow","Nyssa","Paris","Zadie","Maya"},
            {"Memorizio", "Silente", "Dumbo", "Byto", "Dalezio", "Selene", "Granpasso", "Paderma", "Pomezio", "Jumbo", "Ahmed", "Motty", "Raja", "Dante", "Zampone", "Zannone", "Avoride", "Annibale", "Nino", "Baloon", "Ortone", "Nenè", "Efi", "Mavi", "Magnani", "Josephine", "Rumba", "Tricky"}
    };

    // Attributi di istanza
    private String nome;
    private double peso;

    // Metodi privati

    // Costruttore
    Animale(String nome, double peso) {
        this.nome = nome;
        this.peso = peso;
    }

    // Metodi pubblici
    public static String newName(int array) {
        Random r = new Random();
        return nomi[array][r.nextInt(nomi[array].length)];
    }

    public String className() {
        return this.getClass().getName();
    }

    // Getters
    public String getNome() { return nome; }
    public double getPeso() { return peso; }

    // Setters

    // Metodi astratti
    public abstract double costo();
}